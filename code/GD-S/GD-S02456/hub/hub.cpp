#include <bits/stdc++.h>
#define ll long long
using namespace std;

int c,t;

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	cin>>c>>t;
	for(int i = 0;i < t;i++){
		int a,b;
		cin>>a>>b;
		cout<<a - b<<endl;
	}
	
	return 0;
}
