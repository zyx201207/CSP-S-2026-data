#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N=5e5+5;
ll n,m_m,ans;
ll a[N],usednum,lastsan;
map<ll,int>mp;
__int128 used,m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m_m;
	m=m_m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mp[a[i]]++;
	}
	sort(a+1,a+n+1);
	int new_n=unique(a+1,a+n+1)-a-1;
	/*for(int i=1;i<=new_n;i++){
		cout<<a[i]<<' '<<mp[a[i]]<<'\n';
	}
	cout<<'\n';*/
	for(int i=1,j=1;i<=new_n;i++){
		used+=(a[i]-a[i-1])*usednum;
		usednum+=mp[a[i]];
		//cout<<i<<":"<<(ll)usednum<<"\n";
		while(1){
			if(used<=m)break;
			//cout<<(ll)used<<' '<<usednum<<" "<<lastsan<<'\n';
			if(lastsan){
				if((__int128)(a[i]-a[j])*lastsan<=used-m){
					used-=(__int128)(a[i]-a[j])*lastsan;
					usednum-=lastsan;
					lastsan=0;
					j++;
				}
				else{
					ll cut=(__int128)(a[i]-a[j]+1+used-m)/(a[i]-a[j]);
					used-=(__int128)(a[i]-a[j])*cut;
					usednum-=cut;
					lastsan-=cut;
					if(lastsan==0)j++;
				}
			}
			else if((__int128)(a[i]-a[j])*mp[a[j]]<=used-m){
				used-=(__int128)(a[i]-a[j])*mp[a[j]];
				usednum-=mp[a[j]];
				j++;
			}
			else{
				lastsan=(__int128)(a[i]-a[j]+1+used-m)/(a[i]-a[j]);
				used-=(__int128)(a[i]-a[j])*lastsan;
				usednum-=lastsan;
				lastsan=mp[a[j]]-lastsan;
				if(lastsan==0)j++; 
			}
			//cout<<(ll)used<<' '<<usednum<<" "<<lastsan<<'\n';
		}
		//cout<<i<<":"<<(ll)usednum<<"\n";
		ans=max(ans,usednum);
	} 
	cout<<ans;
	return 0;
}
