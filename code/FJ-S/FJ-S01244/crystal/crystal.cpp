#include<bits/stdc++.h>
using namespace std;
	int a[500005];
    int maxx=-1e9;
	int maxn=-1e9;
	int s[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
int x=0;
for(int i=1;i<=n;i++){
	cin>>a[i];
	maxx=max(maxx,a[i]);
}
for(int i=1;i<=n;i++){
	if(a[i]==maxx){
		continue;
	}else{
		maxn=max(maxn,a[i]);
		x=i;
	}
}
for(int i=1;i<=n;i++){
	if(i!=x){
		s[i]=abs(maxn-a[i]);
	}
}
sort(s,s+n+1); 
int ans=0;
for(int i=1;i<=n;i++){
	if(m-s[i]<0){
	break;
	}else{
		m=m-s[i];
		ans++;
	}
}
cout<<ans;
	return 0;
}
