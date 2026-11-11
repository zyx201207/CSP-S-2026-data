#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
	int n;
	cin>>n;
	vector<int> m(n+1);
	vector<char> b(n+1);
	int cnt=0;
	for(int i=1;i<=n;i++){
		cin>>m[i]>>b[i];
		cnt+=m[i];
	} 
	vector<int> q(n+2);
	vector<char> cq(n+2);
	int lq=0;
	int sum=0;
	cnt/=2;
 	for(int i=1;i<=n;i++){
		sum+=m[i];
		if(sum<=cnt){
			q[++lq]=m[i];
			cq[lq]=b[i];
		}
		else if(sum-m[i]<cnt){
			q[++lq]=(cnt-(sum-m[i]));
			cq[lq]=b[i];
		}
	}
	sum=0;
	vector<int> h(n+2);
	vector<char> ch(n+2);
	int lh=0;
	for(int i=n;i>=1;i--){
		sum+=m[i];
		if(sum<=cnt){
			h[++lh]=m[i];
			ch[lh]=b[i];
		}
		else if(sum-m[i]<cnt){
			h[++lh]=(cnt-(sum-m[i]));
			ch[lh]=b[i];
		}
	}
	int ans=0;
	int l=1,r=1;
	while(l<=lq&&r<=lh){
		if(q[l]>=h[r]){
			if(cq[l]!=ch[r]){
				ans+=h[r];
				q[l]-=h[r];
				r++;	
			}
			else{
				q[l]-=h[r];
				r++;
			}
		}
		else{
			if(cq[l]!=ch[r]){
				ans+=q[l];
				h[r]-=q[l];
				l++;
			}
			else{
				h[r]-=q[l];
				l++;
			}
		}
	}
	cout<<ans;
} 
signed main(){
	cin.tie(0)->sync_with_stdio(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int T=1;
//	cin>>T;
	while(T--){
		solve();
	} 
}
