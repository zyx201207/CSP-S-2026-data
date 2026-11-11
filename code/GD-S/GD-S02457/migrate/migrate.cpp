#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+10;
ll ans;
ll c,t,n,d;
ll x[N],k[N];
bool find(int a,int b){
	int r=0;
	int m=1;
	int lst=0;
	bool f=0;
	for(int i=a;i<=b;i++){
		if(i!=a&&abs(x[i]=x[i-1])>d){
			f=1;
			break;
		}
		if(abs(x[i]-x[lst])>d){
			m++;
			lst=i-1;
		}else{
			f=1;
		}
	}
	if(f==1)return 0;
	for(int i=a;i<=b;i++){
		r*=k[i];
	}
	if(r==2)return 1;
	else return 0; 
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(x[i]+d>x[j]){
					k[i]++;
				}else{
					break;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+3;j<=n;j++){
				if(find(i,j)){
					ans++;
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
