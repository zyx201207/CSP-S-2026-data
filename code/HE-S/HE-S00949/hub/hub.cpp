#include<bits/stdc++.h>
using namespace std;
long long a[2000001],n,c,t,m,b[2000001];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> c >> t >> n >> m;
	for(int i=0;i<n;i++){
		cin >> a[i] >> b[i];
	}
	for(int i=1;i<n;i++){
		cout << i << endl; 
		if(i>4) break;
	}
	return 0;
}
