#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","r",stdout);
	int c,t;
	cin>>c>>t;
	int n,d;
	int a[1000];
	int s[t];
	int b;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		s[i]=0;
		for(int j=1;j<=n;j++){
			cin>>a[j];
		}
		for(int z=1;z<=n;z++){
			for(int g=1;g<=n-z;g++){
				if(a[z+g]-a[z]<=2){
					b+=1;
				}
			}
			if(b>=1){	
				s[z]+=1;
			}
		}
		
	}
	for(int h=t;h>=1;h--){
		cout<<s[h]<<'\n';
	}
	return 0;
}
