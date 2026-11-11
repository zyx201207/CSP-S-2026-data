//GZ-S00336 贵阳市第九中学 张宛钰 
#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+10;
int c,t,n,d;
int x[maxn];
bool p=true;
int ca;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			if(i>2){
				if((x[i]-x[i-1])==(x[i-1]-x[i-2])) ca=x[i]-x[i-1];
				else p=false;
			}
		}
		if(p){
			int t=2;
			while((t*d)<ca){
				t+=2;
			}
			t/=2;
			cout<<(n-(3*t))<<endl;
		}
	}
	
	return 0;
}
