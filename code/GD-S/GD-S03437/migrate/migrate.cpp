#include<bits/stdc++.h>
using namespace std;
long long x[2000005];
int main(){
	freopen("migrate.in","w",stdin);
	freopen("migrate.out","r",stdout);
	int c,t,n,d,cnt = 0;
	cin>>c>>t;
	for(int i = 1;i <= t;i++){
		cnt = 0;
		cin>>n>>d;
		for(int j = 1;j <= n;j++){
			cin>>x[j];
		}
		for(int j = 1;j <= n;j++){
			for(int z = j;z <= n;z++){
				if(abs(x[j] - x[z]) == d + 1) cnt++;
			}
		}
		cout<<cnt<<' ';
	}
	return 0;
} 
