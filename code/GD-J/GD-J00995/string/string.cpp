#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define PII pair<int,int>
using namespace std;
const int N = 200010;
int n;
ll sum;
struct node{
	ll w;
	char c;
}a[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		ll x;
		char c;
		cin >> x >> c;
		a[i] = {x,c};
		sum+=x;
	}
	string s;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= a[i].w;j++)s+=a[i].c;
	}
	ll ans = 0;
	int i = 0,j = sum-1;
	while(i<=j){
		if(s[i]!=s[j])ans++;
		i++,j--;
	}
	cout << ans;
	return 0;
}
