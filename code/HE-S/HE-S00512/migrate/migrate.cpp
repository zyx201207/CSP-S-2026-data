#include<bits/stdc++.h>
using namespace std;
int a[2000100];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		int n,d;
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>a[i];
		}
		int maxwide=0,maxj=0;
		for(int j=1;j<=n-1;j++){
			if(maxwide<a[j+1]-a[j]){
				maxwide=a[j+1]-a[j];
				maxj=j;
			}
		}
		if(maxwide>d){
			if(n-(n-maxj)<2*d){
				cout<<0;
			}
			else if(n-(n-maxj)==2*d){
				cout<<1;
			}
			else if(n-(n-maxj)>2*d){
				cout<<2;
			}
		}
		else{
			if(n<2*d){
				cout<<0;
			}
			else if(n==2*d){
				cout<<1;
			}
			else if(n>2*d){
				cout<<2;
			}
		}
		cout<<endl;
	}
	return 0;
}
