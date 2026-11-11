#include<bits/stdc++.h>
using namespace std;
string s,ss;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	long long n,cnt=0;
	cin>>n;	
	long long a[n+1],x=1,y=n;
    char c[n+1];	
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	if(x+1==y){
			if(c[x]!=c[y]){
		cnt+=min(a[x],a[y]);
	     }
	     if(a[x]!=a[y]&&x+1!=y){
	     	cnt+=abs(a[x]-a[y]);
	     	a[x+1]-=abs(a[x]-a[y]);
		 }
	}
	while(x+1!=y){
	if(c[x]!=c[y]){
		cnt+=min(a[x],a[y]);
		if(min(a[x],a[y])==a[x])a[x+1]-=abs(a[x]-a[y]);
		else a[y-1]-=abs(a[x]-a[y]);
	     }
	     if(a[x]!=a[y]&&x+1!=y){
	     	cnt+=abs(a[x]-a[y]);
	     	a[x+1]-=abs(a[x]-a[y]);
		 }
	     x++,y--;
	}
	cout<<cnt;
	return 0;
}
