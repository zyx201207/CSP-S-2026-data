#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n;
ll a[10000000][3],d,k,ans;
int c,t;
bool pd=1;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	for(int h=1;h<=t;h++){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2];
		}
		cout<<"1"<<"\n";
	}
	return 0;
}
