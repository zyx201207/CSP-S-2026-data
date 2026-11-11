#include<bits/stdc++.h>
using namespace std;
int c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int z=1;z<=t;z++){
		int n,d,cnt=0;
		long long x[2000005];
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=2;i<n;i++){
			if(x[i+2]-x[i]<d&&x[i+1]-x[i-1]<d){
				cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
