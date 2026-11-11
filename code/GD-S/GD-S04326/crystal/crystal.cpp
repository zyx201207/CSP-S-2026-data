#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define fre
const int maxn=5e5+5;
ll a[maxn],s[maxn];//数，前缀和 
ll n,m;
bool check(int u,int v){//判断a[u]的此前v个数与其的差的和是否<=m 
	return (a[u]*v-s[u-1]+s[u-v-1])<=m;//a[u]-a[u-1]+a[u]-a[u-2]+……+a[u]-a[u-v]=a[u]*v-s[u-1] 
}
int main(){
	#ifdef fre
		freopen("crystal.in","r",stdin);
		freopen("crystal.out","w",stdout);
	#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	//cout<<endl;
	int ans=0; 
	for(int i=1;i<=n;i++){//考虑前i个数
		int l=0,r=i;//最少一个也不能与a[i]持平，最多此前全部与a[i]持平
		//int k=0;//k为可行答案 
		while(l<=r){
			int mid=(l+r)/2; 
			//cout<<i<<' '<<mid<<' '<<a[i]*mid-s[i-1]+s[i-mid-1]<<endl;
			if(check(i,mid)){
				//k=l; 
				l=mid+1; 
			} 
			else r=mid-1; 
		}
		ans=max(ans,max(l,r));
	} 
	cout<<ans;
} 
