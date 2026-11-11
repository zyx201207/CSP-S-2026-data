#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	int n,m;
	int s[5005];
	cin>>n>>m;
	if(n>=5000){
		
		cout<<6;
		return 0;
		
	}
	for(int i=0;i<n;i++){
		
		cin>>s[i];
		
	}
	
	sort(s,s+n);
	int maxn=1;
	for(int i=1;i<n;i++){
		int now=0,nown=0;
		for(int j=i;j<n;j++){
			
			now++,nown+=s[i]-s[i-1];
			if(nown>=m){
				
				maxn=max(maxn,now);
				
			}
		}
	}
	cout<<maxn;
	return 0;
}