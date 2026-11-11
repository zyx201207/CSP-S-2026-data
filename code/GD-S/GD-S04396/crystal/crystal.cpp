#include<bits/stdc++.h>

#define fr(i,l,r) for(int i=(l);i<=(r);i++)
#define fo(i,l,r) for(int i=(l);i<(r);i++)
#define fd(i,r,l) for(int i=(r);i>=(l);i--)

#define LL long long

using namespace std;

const int N=5e5+5;

int n,Ans;
int l,r;
LL m,a[N],sm;

int main(){

	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	ios::sync_with_stdio(false),cin.tie(nullptr);

	cin>>n>>m;
	fr(i,1,n){
		cin>>a[i];
	}
	sort(a+1,a+n+1);

	Ans=1;
	sm=0;l=r=1;
	while(r<n){
		sm+=(r-l+1)*(a[r+1]-a[r]);
		r++;
		while(sm>m){
			sm-=(a[r]-a[l]);
			l++;
		}
		Ans=max(Ans,r-l+1);
	}

	cout<<Ans<<"\n";

	return 0;
}