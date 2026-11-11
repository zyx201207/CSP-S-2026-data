#include<bits/stdc++.h>
using namespace std;
int n,c,t;
long long a[200005],d,ch,tp;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c;
	cin>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){ 
			cin>>a[i];
		}
		ch=a[2]-a[1];
		tp=d/ch*2-1;
		cout<<n-tp<<"\n";
	}
	return 0;
}
