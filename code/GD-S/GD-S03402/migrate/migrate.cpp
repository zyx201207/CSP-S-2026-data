#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6;
int a[MAXN];
int c,t;
int n,d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int c=a[n]-a[1];
		c/=d;
		int sum=a[n]-c*d;
		cout<<sum;
	}
	return 0;
}
