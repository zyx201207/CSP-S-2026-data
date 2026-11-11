#include<bits/stdc++.h>
using namespace std;
long long a[200006];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int n,m,x,y,s,l;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		s=0;
		cin>>x>>y;
		for(int j=0;j<x;j++){
			cin>>a[j];
		}
		for(int j=0;j<x-y;j++){
			l=0; 
			for(int z=1;z<=y;z++){
				if(abs(a[j]-a[j+z])<=y&&abs(a[j+z]-a[j+y])<=y){
					cout<<j<<' '<<z<<endl;
					l++;
				}
				else if(abs(a[j]-a[j+z])<=y&&abs(a[j+z]-a[j+z+d])<=y&&abs(a[j+z+d]-a[j+y])<=y){
					cout<<j<<' '<<z<<endl;
					l++;
				}
			}
			if(l==2) s++;
		}
		cout<<s<<endl; 
	}
	 

	return 0;
}

