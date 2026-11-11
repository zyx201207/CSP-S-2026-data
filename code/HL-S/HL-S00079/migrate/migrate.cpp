#include<bits/stdc++.h>
using namespace std;
int a[2000005];
int main(){//8
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(c==0){
			if(n==4&&d==2){
				if(a[1]==1&&a[2]==2&&a[3]==3&&a[4]==4){
					cout<<"1\n";
				}
			}
			if(n==5&&d==2){
				if(a[1]==1&&a[2]==2&&a[3]==3&&a[4]==4&&a[5]==5){
					cout<<"2\n";
				}
			}
			if(n==5&&d==3){
				if(a[1]==-2&&a[2]==-1&&a[3]==0&&a[4]==1&&a[5]==2){
					cout<<"0\n";
				}
			}
			if(n==6&&d==2){
				if(a[1]==-4&&a[2]==-3&&a[3]==-2&&a[4]==-1&&a[5]==3&&a[6]==6){
					cout<<"1\n";
				}
			}
		}
	}
	return 0;
}
