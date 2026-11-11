#include <bits/stdc++.h>
using namespace std;
int s[200001];
char id[200001];
int main(){
	
	freopen("string.in","r","stdin");
	freopen("string.out","w","stdout");
	
	long long ans=0;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i]>>id[i];
	}
	int l=1,r=n+1;
	while(l<=r){
		int j=min(s[l],s[r]);
		if(id[l]!=id[r]){
			ans+=j;
		}
		if(l==r){
			s[l]-=j;
		}
		else{
			s[l]-=j;
			s[r]-=j;
		}
		if(!s[l])l++;
		if(!s[r])r--;
	}
	cout<<ans;
}

