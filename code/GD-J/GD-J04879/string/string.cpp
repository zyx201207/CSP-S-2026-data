#include<bits/stdc++.h>
using namespace std;
const int N=1e9+10;
char k[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,ans=0,s=0; 
	cin>>n;
	for(int i=0;i<n;i++){
		int v;
		char c;
		cin>>v>>c;
		for(int i=0;i<v;i++){
			k[s+i]=c;
		}
		s+=v;
	}
	for(int i=0;i<s/2;i++){
		if(k[i]!=k[s-i-1])ans++;
	}
	cout<<ans;
	return 0;
} 
