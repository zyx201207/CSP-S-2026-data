#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.ou","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int j=1;j<=t;j++){
	
		int a,b,n[10000];
		cin>>a>>b;
		for(int i=1;i<=a;i++){
			cin>>n[i];
		}
		int c=n[1]+b,cnt=0;
		for(int i=2;i<=a;i++){
			if(c<n[i] && n[i]<=c+b){
				cnt++;
			}
		}
		cout<<cnt<<endl;
	}
}
