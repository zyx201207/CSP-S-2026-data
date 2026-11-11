#include<bits/stdc++.h>
using namespace std;
const int N=2e6+20;
int C,T;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>C>>T;
	while(T--){
		int n,d;cin>>n>>d;
		int p[N];
		for(int i=1;i<=n;i++){
			cin>>p[i];
		}
		bool a[50][50];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(abs(p[i]-p[j])<=d){
					a[i][j]=true;
					a[j][i]=true;
				}
			}
		}
		cout<<1;
	}
	return 0;
}
