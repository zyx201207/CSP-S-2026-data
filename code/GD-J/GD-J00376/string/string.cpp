#include <bits/stdc++.h>
using namespace std;
char c[30];
int s[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;
	int ff=1;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i]>>c[i];
		if(s[i]!=1) ff=0;
	}
	int l=1,r=n;
	long long ans=0;
	bool f=1;
	while(l<r&&ff==0){
		f=1;
		if(c[l]==c[r]) f=0;
		if(s[l]<s[r]){
			s[r]-=s[l];
			if(f==1) ans+=s[l];
			l++;
		}
		else if(s[l]>s[r]){
			s[l]-=s[r];
			if(f==1) ans+=s[r];
			r--;
		}
		else if(s[l]==s[r]){
			if(f==1) ans+=s[l];
			l++;r--;
		}
	}
	if(ff==0)
	cout<<ans;
	else{
		int p=0;
		for(int i=1;i<=n/2;i++){
			if(c[i]==c[n+1-i])
			p++;
		}
		cout<<n/2-p;
	}
	return 0;
}
