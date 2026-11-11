#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i=0;i<t;i++){
		int n,d;
		cin>>n>>d;
		int x[n];
		for(int i=0;i<n;i++){
			cin>>x[i];
		}
		if(n<=2){
			cout<<0;
			break;
		}
		else if(d==1){
			cout<<0;
			break;
		}
		else{
			int p=n;
			for(int j=0;j<n-1;j++){
				if(x[j+1]-x[j]>d){
					p=j+1;
				}
			}
			cout<<(x[p-1]-x[0])%d;
			break;
		}
	}
	return 0;
}
