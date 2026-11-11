#include<bits/stdc++.h>
using namespace std;
int n,m,cnt,d;
int x[500010];
int a[500010];
int main(){
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(c==11 || c==12){
			if(x[3]-x[1]>d){
				cout<<0<<endl;
			}
			else{
				cout<<n-2;
			}
		}
	}
	
	return 0;
}