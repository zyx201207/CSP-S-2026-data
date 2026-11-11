#include <bits/stdc++.h>
using namespace std;
int c,num=0,t;
int main(){
	freopen("migraye.in","r",stdin); 
	freopen("migrate.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		int n,d;
		cin>>n>>d;
		vector<int> x(n-1);
		for(int j=1;j<n;j++){
		cin>>x[j];
		}for(int j=1;j<=n-4;j++){
		int l=j,r=l+4;
		if(abs(x[l+1]-x[l])<=d&&abs(x[l+2]-x[l+1])<=d&&abs(x[r]-x[l+2])<=d){
			num++;	
			}
		}
		cout<<num<<endl;
	}
	return 0;
}
