#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int t;
	cin>>t;
	int a;
	string n;
	char x;
	int maxx=0;
	while(t--){
		cin>>a>>x;	
		n+=x;
		maxx=max(maxx,a);
	}
	string m=n;
	reverse(n.begin(),n.end());
	int sum=0;
	for(int i=0;i<n.size();i++){
		if(n[i]!=m[i]) sum++;
	}
	cout<<sum*maxx/2;
	return 0;
}
