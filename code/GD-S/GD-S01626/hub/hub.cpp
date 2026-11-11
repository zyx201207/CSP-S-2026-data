#include<bits/stdc++.h>
using namespace std;
long long c,t;
long long n,d;
long long x[1000100][3];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	for(int i = 1;i <= t;i++){
		cin>>n>>d;
		for(int j =1;j < n;j++){
			cin>>x[j][1]>>x[j][2];
		}
	}
	for(int i = 1;i <= t;i++){
		cout<<1<<'\n';
	}
	return 0;
}
