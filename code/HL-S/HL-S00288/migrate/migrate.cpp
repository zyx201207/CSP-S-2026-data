#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll heyiwei,t,n,m,f[200100];
bool A=1;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cout<<"dsfd";
	scanf("%ld%ld",&heyiwei,&t);
	while(t--){
		memset(f,0,sizeof(f));
		scanf("%ld%ld",&n,&m);
		for(int i=1;i<n+1;i++){
			scanf("%ld",&f[i]);
			if(f[i]-f[i-1]!=f[i-1]-f[i-2]&&i!=1&&i!=2){
				A=0;
			}
		}
		if(A){
			if(m<f[2]-f[1]){
				cout<<0;
				continue;
			}else{
				ll sum=0;
				m/=f[2]-f[1];
				for(int i=1;i<n;i++){
					sum+=(n-i-1)/m;
				}
				cout<<sum<<endl;
				continue;
			}
		}
	}
	return 0;
}
//Enn...Sometime I want to migrate to a second planet.
