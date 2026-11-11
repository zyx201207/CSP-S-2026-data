#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,ans;
int a[N],c[N],gc;
bool sp=1;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int st=1,res=0;
	for(int i=2;i<=n;i++){
		int p=(a[i]-a[i-1])*(i-1);
		if(res+p<=m){
			res+=p;
			st=i;
		}
		else break;
	}
	ans=max(ans,st);
	int l=1;
	for(int i=st+1;i<=n;i++){
		res+=(a[i]-a[i-1])*(i-l);
		while(res>m&&l<i){
			res-=(a[i]-a[l]);
			l++;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans<<endl;
	return 0;
} 
