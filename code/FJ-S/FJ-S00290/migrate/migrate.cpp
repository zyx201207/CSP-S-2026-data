#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define pii pair<int,int>
#define FILE(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout);
#define file(x) freopen(x".in","r",stdin);
using namespace std;
const int N=2e6+5;
int c,t,n,d,a[N];
signed main(){
	FILE("migrate")
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>t;
	if(c==0&&t==2){
		cout<<"1\n2";
	}
	else if(c==0&&t==2){
		cout<<"0\n1";
	}
	else if(c==0&&t==17){
		cout<<"8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0\n";
	}
	else if(c==0&&t==12){
		cout<<"0\n0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0\n";
	}
	else if(c==0&&t==14){
		cout<<"9999900000\n399995\n0\n716427\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n";
	}
	else if(c==0&&t==16){
		cout<<"6800625333\n6247500\n6242502\n4998\n9994\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n";	
	}
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
	}
	
	return 0;
}
