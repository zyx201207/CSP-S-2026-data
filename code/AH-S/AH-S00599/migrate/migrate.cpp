#include<bits/stdc++.h>
using namespace std;
int c,t,a,k,f[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	if(c==11||c==12){
		for(int i=1;i<=t;i++){
			int ss=0;
			cin>>a>>k;
			for(int j=1;j<=a;j++) cin>>f[j];
			sort(f+1,f+a+1);
			k/=(f[2]-f[1]);
			for(int j=k;j<=a;j+=k){
				if(j<4) continue;
				ss+=a-j+1;
			}
			cout<<ss<<'\n';
		}
	}
	return 0;
}
