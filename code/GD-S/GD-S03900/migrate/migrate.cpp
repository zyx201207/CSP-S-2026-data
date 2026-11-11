#include<bits/stdc++.h>
using namespace std;
int a[500050];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int g=1;g<=t;g++){
		int n,d;
		cin>>n>>d;
		int b=1;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			
		}		
		cout<<n-d-1<<endl;
	}
}
