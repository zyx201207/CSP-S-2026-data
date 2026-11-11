#include<bits/stdc++.h>
using namespace std;
string s[200005],s1[200005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a;
	cin>>n;
	int t=1;
	string b;
	while(n--){
		cin>>a>>b;
		for(int t=t;t<=t+a;t++){
		s[t]=b;
		
	}
	}
	int i=1;

	for(int t=t;t>=1;t--){
		i++;
		s1[i]=s[t];
	}
	int ans=0;
	for(int i=1;i<=t;i++){
		if(s[i]!=s1[i])
		{
			ans++;
		}
	}
	cout<<ans<<'\n';
	return 0;
}
