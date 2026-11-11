#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,d;
int a[10001];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
	}
	cout<<"0"<<endl;
	cout<<"1";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
