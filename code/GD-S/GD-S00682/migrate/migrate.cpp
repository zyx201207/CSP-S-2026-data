#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,h,num=0;
long long x[2000005],y[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=0;i<t;i++){
		cin>>n>>d;
		for(int j=0;j<n;j++){
			cin>>h;
			x[h]==1;
		}
	for(int i=n-1;i>=0;i--){
		for(int j=i-1;j>=0;j--){	
			if(x[i]-x[j]<=d){
				y[i]=x[i]-x[j];
			}
		}
	}
	for(int i=0;i<n;i++){
		if(y[i]==y[i+1]){
			num++;
		}
	}
	cout<<num;
	return 0;
	}
}
