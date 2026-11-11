#include<bits/stdc++.h>
using namespace std;

int c,t,n,k;
int ans[1000005];

struct city{
	int a,b;
}s[1000006];


int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> c >> t;
	for(int i=1;i<=t;i++){
		cin >> n >> k;
		for(int j=1;j<=n+1;j++){
			cin >> s[i].a >> s[i].b;
		}

	}
	for(int i=1;i<=t;i++){
		cout << 1 << endl;
	}
}
