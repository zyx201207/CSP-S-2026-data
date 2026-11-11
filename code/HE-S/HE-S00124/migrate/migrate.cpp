#include <bits/stdc++.h>
using namespace std;
long long n,d,total=0;
const int N=2e6+10;
long long a[N];
int c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		total=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n-3;i++){
			if(a[i+1]-a[i]<=d&&a[i+3]-a[i+1]<=d&&a[i+3]-a[i+2]<=d&&a[i+2]-a[i]<=d&&a[i+3]-a[i]>d){
				total++;
			}
		}
		cout<<total<<endl;
	}
	return 0;
}
