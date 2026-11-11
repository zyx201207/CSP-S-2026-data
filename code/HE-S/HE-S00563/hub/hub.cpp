#include<bits/stdc++.h>
using namespace std;
long long a0,a,sum,ans;
int x,y,z[2000005];
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
	cin>>a0>>a;
	for(int i=1;i<=a;i++){
		cin>>x>>y;
		ans=x*y;
		for(int j=1;j<x;j++){
			cin>>z[i];
			sum+=z[i];
		}
		cout<<sum/ans<<endl;
	}
	return 0;
}
