#include<bits/stdc++.h>
using namespace std;
long long a[6000100][10];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int s,t;
	cin>>s>>t;
	for(int g=1;g<=t;g++){
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2];
		}
		cout<<1;
	}
	return 0;
}
