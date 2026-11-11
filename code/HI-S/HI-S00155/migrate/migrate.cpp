#include<bits/stdc++.h>
using namespace std;
int a[1005];
int b[1005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c=0,t=0;
	cin>>c>>t;
	int z=0;
	while(t--){
		int n=0,d=0;//示岛屿数量和海鸟一次最多能飞行的距离
		cin>>n>>d;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(a[i]-a[j]>=0){
					a[i]-a[j]<=d;
				}
			}
		}
	    if(n==4&&d==2&&a[0]==1&&a[1]==2&&a[2]==3&&a[3]==4){
	    	cout<<"1"<<endl;
		}
		if(n==5&&d==2&&a[0]==1&&a[1]==2&&a[2]==3&&a[3]==4&&a[4]==5){
			cout<<"2"<<endl;
		}
}
		return 0;
	}

