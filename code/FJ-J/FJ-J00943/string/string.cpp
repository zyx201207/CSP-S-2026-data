#include<bits/stdc++.h>
using namespace std;
string s;
char e[1000005];
long long len[1000005],l=1,ans,n,r;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	r=n;
	for(int i=1;i<=n;i++){
		cin>>len[i]>>e[i];
		
	}
	
	while(l<r){
		len[l]--;
		len[r]--;
		if(e[l]!=e[r])ans++;
		if(len[l]==0)l++;
		if(len[r]==0)r--;
	}
	cout<<ans;
	return 0;
}
