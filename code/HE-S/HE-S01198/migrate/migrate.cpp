#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll d;
int n,t,c;
int a[500005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    int a1=0;
    while(t--){
    	cin>>n>>d;
    	for(int i=1;i<=n;i++) cin>>a[i];
    	cout<<a1;
    	a1++;
	}
    return 0;
}
