//GZ-J00265贵阳市第三中学王上清 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define plc pair<ll,char>
ll n;
ll cnt,ans;
void ji(){
	cin>>n;
	vector<plc>s1(n+1);
	vector<plc>s2(n+1);
	for(ll i=1;i<=n;i++){
		cin>>s1[i].first>>s1[i].second;
		s2[n-i+1].first=s1[i].first;
		s2[n-i+1].second=s1[i].second;
		ans+=s1[i].first;
	}
	ll fl=0;
	for(ll i=1,j=1;j<=n,i<=n;){
		if(s1[i].second==s2[j].second){
		     cnt+=min(s1[i].first,s2[i].first);
		}
		if(s1[i].first<s2[j].first){
			s2[j].first-=s1[i].first;
			i++;
		}if(s1[i].first>s2[j].first){
			s1[i].first-=s2[j].first;
			j++;
		}
		if(s1[i].first==s2[j].first){
			if(s1[i].second==s2[i].second){
				cnt+=s1[i].first;
			}
			i++;
			j++;
		}
	}
	cout<<(ans-cnt)/2<<endl;
	return;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int t=1;
	//cin>>t;
	while(t--){
		ji();
	}
	return 0;
}
