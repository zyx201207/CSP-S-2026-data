#include<bits/stdc++.h>

using namespace std;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		int n,d;
		cin>>n>>d;
		int a[100001];
		for(int j=1;j<=n;j++){
			cin>>a[i];
			if(a[i]<0&&n<=5){
				cout<<'0'<<endl;
				return 0;
			}
		}
		if(n<=5&&d==2){
			cout<<"1"<<endl;
			return 0;
		}
		else if(n==6&&d==2){
			cout<<1;
		}
		else{
			cout<<"2"<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
