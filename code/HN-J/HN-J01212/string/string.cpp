#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,maxx,ans;
string s;
int L[200005],R[200005];
int a[200005];
char c[200005];
void solve1(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	int cnt=0;
	for(int i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-1-i]) cnt++;
	}
	cout<<cnt;
}
void solve2(){
	int sum=R[n];
	for(int i=1;i<=n;i++){
		if(L[i]>sum/2) continue;
		if(R[i]>sum/2) continue;
		int it1=upper_bound(L+1,L+n+1,sum-R[i]+1)-L;
		it1--;
		int it2=lower_bound(R+1,R+n+1,sum-L[i]+1)-R;
		if(it1==it2){
			ans+=(sum-L[i]+1)-(sum-R[i]+1)+1;
		}
		else {
			for(int j=it1+1;j<=it2-1;j++){
				if(c[j]!=c[i]) ans+=R[i]-L[i]+1;
			}
			if(c[it1]!=c[i]){
				ans+=R[it1]-(sum-R[i]+1)+1; 
			}
			if(c[it2]!=c[i]){
				ans+=(sum-L[i]+1)-L[i]+1;
			}
		}
	}
	cout<<ans;
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		maxx=max(maxx,a[i]);
		L[i]=R[i-1]+1;
		R[i]=L[i]+a[i]-1;
	}
	if(maxx<=500){
		solve1();
	}
	else {
		solve2();
	}
	return 0;
}
