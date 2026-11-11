#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n;
long long m,a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	int l,r;
	long long w=0;
	l=1;
	for(r=2;r<=n;r++){
		w+=(a[r]-a[r-1])*(r-l);
		if(w>m){
			w-=(a[r]-a[l]);
			l++;
		}
	}
	cout<<r-l;
	return 0;
}
