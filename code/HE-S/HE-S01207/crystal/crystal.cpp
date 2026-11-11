#include <bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
long long a[MAXN],n,m,r,cnt=0,mx,ans=0;
queue<long long> q;
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m; r=m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n); q.push(a[1]); cnt++; mx=a[1];
	for(int i=2;i<=n;i++){
		if(r-cnt*(a[i]-mx)>=0){
			r-=cnt*(a[i]-mx); cnt++;
			q.push(a[i]); mx=a[i];
		} else{
			while(!q.empty()&&(r<cnt*(a[i]-mx))){
				r=r-q.front()+mx; cnt--;
				q.pop();
			} if(q.empty()) mx=a[i];
			r-=cnt*(a[i]-mx); cnt++;
			mx=a[i];
		} ans=max(ans,cnt);
	} cout<<ans;
	return 0;
} 
