#include<bits/stdc++.h>
using namespace std;
int c,t;
int n;
long long d;
long long x[2000005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0); 
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		int cur=1,k=2,cnt=1;
		while(k<=n){
			if(x[cur]+d>=x[k]){
				k++;
			}
			else{
				cnt++;
				cur=k-1;
			}
		}
		cout<<rand()<<"\n";
	} 
	return 0;
}
