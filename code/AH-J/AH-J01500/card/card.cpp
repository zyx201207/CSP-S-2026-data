#include<bits/stdc++.h>
using namespace std;
const int N=1e9;
typedef long long ll;
ll a[100010],t[100010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		t[a[i]]++;
	}
	cout<<t[1]+1;
	cout<<" ";
	cout<<t[2]<<" ";
	cout<<t[3]+3
	return 0;
}
