#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2e5+5;
ll n,x,m,ans,tans;
ll a[N];
string s[N];
bool vis[N],vis2[N];
vector<ll>tmp;
void cheak(ll wh){
	vector<ll>res,cnt,lst;
	cnt.clear();
	lst.clear();
	for(ll i=0;i<=31;i++){
		res.clear();
		for(ll j=tmp.size()-1;j>=0;j--){
			if(s[tmp[j]][i]=='1'&&!vis2[tmp[j]]) res.push_back(tmp[j]);
		}
		if(ans+(ll)res.size()+(ll)cnt.size()<m){
			for(ll j=res.size()-1;j>=0;j--){
				cnt.push_back(res[j]);
				vis2[res[j]]=1;
			}
		}
		else if(ans+(ll)res.size()+(ll)cnt.size()==m){
			for(ll j=res.size()-1;j>=0;j--) cnt.push_back(res[j]);
			tmp=cnt;
			return ; 
		}
		else if(ans+(ll)res.size()+(ll)cnt.size()>m) tmp=lst=res;
	}
	if(ans+(ll)res.size()+(ll)cnt.size()<m){
		for(ll j=lst.size()-1;j>=0;j--){
			if(vis2[lst[j]]) continue;
			ans++;
			if(ans+(ll)cnt.size()>m) break;
			cnt.push_back(lst[j]);
		}
		tmp=cnt;
	}
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	ll maxn=0;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
		x=a[i];
		s[i]="";
		string p;
		while(x>0){
			p=(char)(x%2+'0');
			s[i]+=p;
			x/=2;
		}
		s[i]+=string(32-s[i].size(),'0');
		reverse(s[i].begin(),s[i].end());
	}
	if(m==1){
		cout<<maxn;
		return 0;
	}
	if(m==2&&n<=2000){
		maxn=0;
		for(ll i=1;i<=n;i++){
			for(ll j=i+1;j<=n;j++){
				maxn=max(maxn,(a[i]&a[j]));
			}
		} 
		cout<<maxn;
		return 0;
	}
	if(m==n){
		maxn=a[1];
		for(ll i=2;i<=n;i++) maxn=(maxn&a[i]);
		cout<<maxn;
		return 0;
	}
	for(ll i=0;i<=31;i++){
		tmp.clear();
		for(ll j=1;j<=n;j++){
			if(s[j][i]=='1'&&!vis[j]) tmp.push_back(j);
		}
		if(tmp.size()<=1&&ans==0) continue;
		if((ll)tmp.size()+ans==m){
			ans=-1;
			for(ll j=1;j<=n;j++){
				if(!vis[j]) continue;
				if(ans==-1) ans=a[j];
				else ans=(ans&a[j]);
			}
			for(ll j=tmp.size()-1;j>=0;j--){
				if(ans==-1) ans=a[tmp[j]];
				else ans=(ans&a[tmp[j]]);
			}
			cout<<ans;
			return 0;
		}
		if((ll)tmp.size()+ans<m){
			for(ll j=tmp.size()-1;j>=0;j--) vis[tmp[j]]=vis2[tmp[j]]=1;
		}
		if((ll)tmp.size()+ans>m){
			cheak(i);
			sort(tmp.begin(),tmp.end());
			tans=ans;
			ans=-1;
			for(ll j=1;j<=n;j++){
				if(!vis[j]) continue;
				if(ans==-1) ans=a[j];
				else ans=(ans&a[j]);
			}
			for(ll j=tmp.size()-1;j>=0;j--){
				if(ans==-1) ans=a[tmp[j]];
				else ans=(ans&a[tmp[j]]);
			}
			cout<<ans;
			return 0;
		}
		ans+=tmp.size();
	}
	if(ans<m) cout<<0;
	return 0;
} 
