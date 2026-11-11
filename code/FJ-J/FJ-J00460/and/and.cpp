#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,big;
ll s[100001];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int i=2;i<=n;i++){
		int d=s[i-1]&s[i];
		if(d>big){
			big=d;
		}
	}
	cout<<big;
	return 0;
}
