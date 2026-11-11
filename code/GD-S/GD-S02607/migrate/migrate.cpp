#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,d,c,t,a[N],s[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		bool f=0,p=0;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n-1;i++) s[i]=a[i+1]-a[i];
		for(int i=1;i<=n-1;i++) if(s[i]!=s[i+1]) f=1;
		if(!f){
			for(int i=1;i<=n-1;i++){
				if(abs(a[i]-a[i+1])>d) p=1;
			}
			if(p) cout<<0<<'\n';
			else{
				if(n<4) cout<<0<<'\n';
				else if(n==4) cout<<1<<'\n';
				else cout<<n-4+1<<'\n';
			}
		}
		else{
			if(n<4) cout<<0<<'\n';
			else if(n==4) cout<<1<<'\n';
			else cout<<n-4+1<<'\n';
		}
	}
	return 0;
}
