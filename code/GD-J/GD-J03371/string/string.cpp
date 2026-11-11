#include<bits/stdc++.h>
namespace KH{
using namespace std;
#define int long long
void solve(){
	int n;
	cin>>n;
	vector<pair<int,char> > a(n+1);
	vector<int> b(n+1);
	for(int i=1;i<=n;i++)
		cin>>a[i].first>>a[i].second,
		b[i]=b[i-1]+a[i].first;
	vector<pair<int,char> > sht(1);
	for(int i=1;i<=n;i++){
		int l=b[i-1]+1,r=b[i];
		if((b[n]&1)&&l<=(b[n]>>1)+1&&r>=(b[n]>>1)+1&&l!=r) {
			if(l!=(b[n]>>1)+1&&r!=(b[n]>>1)+1) {
				sht.push_back({((b[n]>>1)+1)-l,a[i].second});
				sht.push_back({1,a[i].second});
				sht.push_back({r-((b[n]>>1)+1),a[i].second});
			}
			else if(l==(b[n]>>1)+1&&r!=((b[n]>>1)+1)){
				sht.push_back({1,a[i].second});
				sht.push_back({r-((b[n]>>1)+1),a[i].second});
			}
			else if(l!=(b[n]>>1)+1&&r==((b[n]>>1)+1)){
				sht.push_back({((b[n]>>1)+1)-l,a[i].second}),
				sht.push_back({1,a[i].second});
			}
		}
		else if(l<=(b[n]>>1)&&r>=(b[n]>>1)+1){
			sht.push_back({(b[n]>>1)-l+1,a[i].second});
			sht.push_back({r-(b[n]>>1),a[i].second});
		}
		else sht.push_back({a[i].first,a[i].second});
	}
	int m=sht.size()-1;
	vector<int> shtb(m+1);
	for(int i=1;i<=m;i++){
		shtb[i]=shtb[i-1]+sht[i].first;
	}
	int ans=0,l=1,r=m;
	for(;l<r;){
		int llr=shtb[l],lll=shtb[l-1]+1;
		int rrl=shtb[m]-shtb[r-1],rrr=shtb[m]-shtb[r]+1;
		if(sht[l].second!=sht[r].second) ans+=min(rrl,llr)-max(lll,rrr)+1;
		if(llr==rrl) l++,r--;
		else if(llr<rrl) l++;
		else if(llr>rrl) r--;
	}
	cout<<ans<<'\n';
}
void main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T=1;
	while(T--){
		solve();
	}
}
#undef int
}
int main(){KH::main();}
