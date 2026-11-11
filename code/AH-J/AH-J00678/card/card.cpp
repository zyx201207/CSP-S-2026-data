#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll cnt[500010],pos[510000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ll n,m;cin>>n>>m;
	queue<ll> card;
	for(ll i=1;i<=n;i++){
		ll x;cin>>x;
		card.push(x);
	}
	for(ll i=1;i<=n;i++){
		ll t=1;
		if(i!=1) card.pop();
		queue<ll> q=card;
		string s;
		memset(pos,0,sizeof pos);s+='0';
		while(!q.empty()){
			t++;
			s+=char(q.front()+48);
			if(pos[q.front()]==0) pos[q.front()]=t;
			else{
				string ss;ll len=s.size();
				for(ll i=1;i<=len;i++){
					if(i>=pos[q.front()]&&i<t){pos[ll(s[i])]=0;continue;}
					ss+=s[i];
				}
				s=ss;
				pos[q.front()]=t;
			}
			q.pop();
		}ll len=s.size();
		cout<<"";
		for(ll j=0;j<len;j++) cnt[ll(s[j])]++;
	}
	for(ll i=49;i<=m+48;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}
