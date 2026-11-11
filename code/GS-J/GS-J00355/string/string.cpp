#include<bits/stdc++.h>
using namespace std;
int g,need[200000000000];
char s[200000000000];
long long ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>g;
	for(int i=1;i<=g;i++){
		cin>>need[i]>>s[i];
	}
	int l=1,r=g;
	for(;l<r;){
		int open=min(need[l],need[r]);
		if(s[l]==s[r]){
			need[l]-=open;
			need[r]-=open;
		}else{
			need[l]-=open;
			need[r]-=open;
			ans+=open;
		}
		if(need[l]==0){
			l++;
		}
		if(need[r]==0){
			r--;
		}
	}
	cout<<ans;
	return 0;
}
