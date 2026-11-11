#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[200005],sum,cnt,summ;
char ch[200005];
unordered_map<ll,char> mp;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		ll temp;
		char c;
		cin>>temp>>c;
		for(int j=sum+1;j<=sum+temp+1;j++){
			mp[j]=c;
		}
		sum+=temp;
	}
	for(int i=1;i<=sum/2;i++){
		if(mp[i]!=mp[sum-i+1]){
			summ++;
		}
	}
	cout<<summ;
	
	
	
	
	
	
	return 0;
}
