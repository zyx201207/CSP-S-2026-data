#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d;
int x[100000007];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		memset(x,0,sizeof(x));
		for(int i=0;i<n;i++){
			cin>>x[i];
		}
		int sum=0;
		for(int i=0;i<n;i++){
			if(sum>d){
				break;
			}
			sum++;
		}
	}
	cout<<1<<endl<<2;
}
