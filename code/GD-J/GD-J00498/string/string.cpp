#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,a[200005],maxn;
char c[200005];

signed main(){
	ios::sync_with_stdio(0),cin.tie(0);

	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);

	cin>>n;
	
	for(int i=1;i<=n;i++)
		cin>>a[i]>>c[i],
		maxn=max(maxn,a[i]);

	if(maxn<=500){
		string s="";
		
		int cnt=0;
		
		for(int i=1;i<=n;i++){
			
			for(int j=1;j<=a[i];j++)
				s+=c[i];
		}
			
		int cnts=s.size()-1;
			
		
//		cout<<cnts<<'\n';
//		cout<<s<<'\n';
				
		for(int i=0;i<=cnts/2;i++)
			if(s[i]!=s[cnts-i]) cnt++;
		
			
//		cout<<"\n";	
		cout<<cnt;
		return 0;
	}
	
	return 0;
}
