#include<bits/stdc++.h>
using namespace std;
int n,s,t,maxn=INT_MIN,minn=INT_MAX;
char a;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s>>a;
		t+=a;
		maxn=max(maxn,int(a));
		minn=min(minn,int(a));
	}
	if(n==1){cout<<0;return 0;}
	if(maxn==minn){cout<<0;return 0;}
	if(t<=2){cout<<0;return 0;}
}
