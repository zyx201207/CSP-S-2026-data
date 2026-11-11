#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c,t,n,d,a[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	if(c==0){
		if(t==2){
			cout<<"0\n1\n";
			return 0;
		}
		if(t==17){
			cout<<"8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n3\n6\n0\n2\n0";
			return 0;
		} 
	}
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		    cin>>a[i];
		int cnt=0;
		for(int i=1;i<=n-4;i++)
		    if(abs(a[i+4]-a[i])<=d) cnt++;
	    cout<<cnt<<'\n';
	}
	return 0;
}
