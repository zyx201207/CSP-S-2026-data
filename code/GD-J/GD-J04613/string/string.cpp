#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int a[n+1]={};
	long long ans(0);
	char c[n+1]={};
	string s="";
	for(int i(0);i<n;i++){
		cin>>a[i]>>c[i];
		for(int j(0);j<a[i];j++)s+=c[i];
	}
	for(int i(0);i<s.size()/2;i++){
		if(s[i]!=s[s.size()-i-1])ans++;
	}
	cout<<ans;
	return 0;
} 

/*
#include <bits/stdc++.h>
using namespace std;
int main(){
//	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int a[n+1]={};
	long long ans(0);
	char c[n+1]={};
	for(int i(0);i<n;i++){
		cin>>a[i]>>c[i];
	}
	int l=0,r=0,lt(0),rt(n-1);
	char lc=c[lt],rc=c[rt];
	while(lt<=rt){
		lc=c[lt],l+=a[lt++];
		while((l>0)&&(lt<=rt)){
			if(r<l)rc=c[rt],r+=a[rt--];
			if(lc!=rc){
				ans+=min(r,l);
			}
			if(r>=l)r-=l,l=0;
			else l-=r,r=0;
//			cout<<l<<" "<<r<<" "<<ans<<'\n';
		}
//		cout<<l<<"  "<<r<<" "<<ans<<" "<<lt<<" "<<rt<<'\n';
	}
	cout<<ans;
	return 0;
} 
*/
