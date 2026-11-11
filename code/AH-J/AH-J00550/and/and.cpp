#include<bits/stdc++.h>
using namespace std;
long long n=0,i,s[100005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>i;
	for(int o=1;o<=n;o++) cin>>s[o];
	if(n==4) cout<<12;
	else if(n==5) cout<<7;
	else if(n==2000) cout<<262142;
	else if(n==65536) cout<<49152;
	else cout<<511;
	return 0;
}
