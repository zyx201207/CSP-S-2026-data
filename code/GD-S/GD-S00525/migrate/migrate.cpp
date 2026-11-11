#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,T;
const int N=2e6+5;
int n,m;
int a[N];
int main(){
	freopen("migrate4.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>m;
		int x=-1;
		bool bj=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(x==-1&&i>=2){
				x=a[i]-a[i-1];
			}
			if(x!=-1&&i>=2){
				if(x!=a[i]-a[i-1])bj=1;
			}
		}
		if(bj==0){
			int len=m/x;
			int t=0;
			long long ans=0;
			for(int i=1;i<=n;i++){
				int t=n-i-len;
				if(t<0)break;
				t=min(t,len-1);
				ans+=t;
			}
			cout<<ans<<"\n";
		}
	} 
	return 0;
}
