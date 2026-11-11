#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10,inf=0x3f3f3f3f;
int n;
int l;

struct node{
	int a;char b;
};
node s[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x>>s[i].b;
		l+=x;
		s[i].a=l;
	}
	int lp1=1,lp2=n;
	int ans=0;
	for(int i=1;i<=l/2;i++){
		char ns1,ns2;
		if(s[lp1].a>=i and s[lp1-1].a<i){
			ns1=s[lp1].b;
		}else{
			lp1++;
			ns1=s[lp1].b;
		}
		int r=l-i+1;
		if(s[lp2].a>=r and s[lp2-1].a<r){
			ns2=s[lp2].b;
		}else{
			lp2--;
			ns2=s[lp2].b;
		}
		if(ns1!=ns2){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
