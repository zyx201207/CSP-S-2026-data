#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N];
int n,mx;
long long m;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int l=1,r=1;
	long long tot=0;
	while(r<=n){
		if(tot+(a[r+1]-a[r])*(r-l+1)<=m){
			r++;
			mx=max(mx,r-l+1);
			tot+=(a[r]-a[r-1])*(r-l);
		}else{
			l++;
			tot-=(a[r]-a[l-1]);
		}//ap++;if(ap<8)
	//	cout<<tot<<" "<<l<<" "<<r<<"\n";
	}cout<<mx;
	return 0;
}
