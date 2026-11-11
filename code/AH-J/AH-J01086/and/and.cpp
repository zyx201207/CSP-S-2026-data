#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n,m;
int a[N],p[N];
bool vis[N];
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	int t=1;
	for(int i=30;i>=0;i--){
		int x=(a[t]>>i);
		if((x%2==1)&&p[i]==0){
			p[i]=a[t];
			vis[t]=1;
			t++;
		}else if(p[i]!=0){
			p[i-1]=a[t]&p[i];
			vis[t]=1;
			t++;
		}
	}
	int ans=INT_MAX;
	for(int i=30;i>=0&&m!=0;i--){
		if(p[i]!=0) ans&=p[i],m--;
	}
	cout<<ans<<endl;
	return 0;
}
