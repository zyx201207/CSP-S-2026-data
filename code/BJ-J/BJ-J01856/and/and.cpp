#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define ll long long
#define pb push_back
#define fir first
#define sec second
const int N=2e5+7;
int n,m,a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	cout<<a[m];
	return 0;
}
