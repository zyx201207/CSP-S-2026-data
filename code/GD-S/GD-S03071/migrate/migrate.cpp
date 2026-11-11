#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,c,n,d,a[2000001],num=0,sum=0;
void note(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n-d;i++){
		sum=0;
		for(int j=1;j<=d;j++){
			if(a[j]<=i+d){
				sum++;
			}
		}
		if(sum==2){
			num++;
		}
	}
	cout<<num<<endl;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		note();
	}
	return 0;
}