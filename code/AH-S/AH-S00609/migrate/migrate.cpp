#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[2000006],s=0;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		s=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(d%2!=0){
			cout<<0<<endl;
		}
		else{
		for(int i=1;i<=n;i++){
			for(int j=i+d+1;j<=n;j++){
				if((long long)abs(x[i]-x[j])>d&&(long long)abs(x[i]-x[j])<2*d)s++;
				}	
			}
		cout<<s<<endl;
		}
	}
	return 0;
} 
