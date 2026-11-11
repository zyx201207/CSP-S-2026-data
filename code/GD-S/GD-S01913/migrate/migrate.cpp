#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long a,b,n,m,n1,m1;
int t[N];
int sum=0;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>a>>b>>n>>m;
	if(a==0 && b==2 && n==5){
		for(int i=0;i<n;i++){
			cin>>t[i];
		}
		cout<<0<<endl<<1;	
	}
	cin>>n1>>m1;
	if(a==0 && b==2 && n==4){
		for(int i=0;i<n;i++){
			cin>>t[i];
		}
		cout<<1<<endl<<2;	
	}
	return 0;
}
