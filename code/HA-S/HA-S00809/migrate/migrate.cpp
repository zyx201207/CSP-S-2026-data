#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,x[500010],y[500010],ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(y[i]<d){
					y[i]+=x[j];
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(y[i]==y[j])ans++;
			}
		}
		cout<<ans;
	}
	return 0;
}
