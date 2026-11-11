#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int c,t;
	cin>>c>>t;
	int a[t];
	for(int i=1;i<=t;i++){
		if(a[i]%2==1) cout<<1;
		else cout<<2;
		cout<<endl;
	}
	return 0;
}

