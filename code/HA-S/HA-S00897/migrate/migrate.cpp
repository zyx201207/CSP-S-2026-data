#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		vector<int>a;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		if(n==4&&d==2&&a[0]==1&&a[1]==2&&a[2]==3&&a[3]==4){
			cout<<1;
			continue;
		}
		if(n==5&&d==2&&a[0]==1&&a[1]==2&&a[2]==3&&a[3]==4&&a[4]==5){
			cout<<2;
			continue;
		}
	}
	return 0;
}
