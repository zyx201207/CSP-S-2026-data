#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n;
long long m,a[N];
int ans=1,l=1,r=1;
int siz=1;
long long cha;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	while(r<=n){
		r++;
		cha+=(a[r]-a[r-1])*siz;
		siz++;
		while(cha>m){
			cha-=(a[r]-a[l]);
			l++;
			siz--;
		}
		if(cha<=m){
			ans=max(ans,siz);
		}
	}
	cout<<ans;
	return 0;
} 

