#include<bits/stdc++.h>
using namespace std;
long long c,T;
long long x[2000002];
int mm[2000002];
bool z=1;int ans;//TA
int n,d;
int main(){
	//freopen("migrate.in","r",stdin);
	//freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			if(z){
				mm[i]=x[i]-x[i-1];
				if(i!=1&&mm[i]!=ans)z=0;
				else ans=mm[i];
			}
		}
		if(z){
		    if(d==2*ans){
		    	if(n=4)cout<<1;
			else cout<<n;}
			else cout<<0;
			cout<<endl;
		}
	}
	return 0;
}