#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int n; ll ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	vector<ll> len(n+1);
	vector<char> ch(n+1);
	ll l=1,r=n,curl=1,curr=0;
	for(int i=1;i<=n;i++){
		cin>>len[i]>>ch[i];
		curr+=len[i];
	}
	while(l<r){
		if(ch[l]==ch[r]){
			if(len[l]<len[r]) curl+=len[l],curr-=len[l],len[r]-=len[l],l++;
			else if(len[l]>len[r]) curl+=len[r],curr-=len[r],len[l]-=len[r],r--;
			else curl+=len[l],curr-=len[r],l++,r--;
		}else{
			if(len[l]<len[r]) curl+=len[l],curr-=len[l],ans+=len[l],len[r]-=len[l],l++;
			else if(len[l]>len[r]) curl+=len[r],curr-=len[r],ans+=len[r],len[l]-=len[r],r--;
			else curl+=len[l],curr-=len[r],ans+=len[l],l++,r--;
		}
	}
	cout<<ans;
	return 0;
}
