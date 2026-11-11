#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+10;
vector<pair<int,int> > h,t;
pair<int,char> a[MAXN];
long long len=0LL;
int n;
void Solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].first>>a[i].second;
		len+=a[i].first;
	}
	if(len&1LL){
		long long sum=0LL;
		for(int i=1;i<=n;i++){
			if(sum>(len>>1)){
				t.push_back(a[i]);
			}else if(sum+a[i].first<=(len>>1)){
				h.push_back(a[i]);
			}else{
				h.push_back(make_pair((len>>1)-sum,a[i].second));
				t.push_back(make_pair(a[i].first-((len>>1)-sum)-1,a[i].second));
			}
			sum+=a[i].first;
		}
	}else{
		long long sum=0LL;
		for(int i=1;i<=n;i++){
			if(sum>=(len>>1)){
				t.push_back(a[i]);
			}else if(sum+a[i].first<=(len>>1)){
				h.push_back(a[i]);
			}else{
				h.push_back(make_pair((len>>1)-sum,a[i].second));
				t.push_back(make_pair(a[i].first-((len>>1)-sum),a[i].second));
			}
			sum+=a[i].first;
		}
	}
	int lsiz=(int)(h.size()),rsiz=(int)(t.size()),l=0,r=rsiz-1,llen=h[l].first,rlen=t[r].first;
	char lch=h[l].second,rch=t[r].second;
	long long ans=0LL;
	while(l<lsiz&&r>=0){
		if(lch!=rch){
			ans+=min(llen,rlen);
		}
		if(llen<rlen){
			rlen-=llen;
			l++;
			llen=h[l].first;
			lch=h[l].second;
		}else{
			llen-=rlen;
			r--;
			rlen=t[r].first;
			rch=t[r].second;
		}
	}
	cout<<ans;
	return;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	Solve();
	return 0;
}