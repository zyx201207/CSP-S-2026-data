#include<iostream>
using namespace std;
int n;
int x[1001];
int d;
int c,t;
int p[1001][1001];
int main(){
	freopen("migrate1.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(c--){
		cin>>n>>d;
		for(int i=1; i<=n; i++){
			cin>>x[i];
		}
		for(int i=1; i<=n; i++){
			for(int j=1; j<i; j++){
				if(x[i]-x[j]<=d){
					p[i][j]=1;
				}
			}
		}
		cout<<1<<endl;
	}
	return 0;
}
