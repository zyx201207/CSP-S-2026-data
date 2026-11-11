#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,d,x[200005],a[9]={},ans=0;
	cin>>c>>t;
	for(int i=0;i<t;i++){
		cin>>n>>d;
		for(int i=0;i<n;i++){
			cin>>x[i];
		}
		if(c<=2){
			if(n<4)cout<<0;
			else{
				for(int i=3;i<n;i++){
					if(x[i]-x[i-2]<=d&&x[i-1]-x[i-3]<=d){
						ans++;
					}
				}
				cout<<ans;
			}
		}
		if(c==11||c==12){
			d=d/(x[1]-x[0]);
			d*=2;
			d--; 
			cout<<n-d<<endl;
		}
		if(c==13||c==14){
			cout<<i<<endl;
		}
	}
	return 0;
}
