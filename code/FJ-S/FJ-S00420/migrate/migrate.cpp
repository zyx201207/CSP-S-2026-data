#include<bits/stdc++.h>
using namespace std;
int c,t;
const int MAXN=2e6+417;
int n,d;
int num[MAXN];
void yarisaki(){
	cin>>n>>d;
	for(int i=1;i<=n;i++)
	{
		cin>>num[i]; 
	}
	cout<<d-1<<endl;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		yarisaki();
	}
	return 0;
}
