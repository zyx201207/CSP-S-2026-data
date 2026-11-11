#include<bits/stdc++.h>
using namespace std;
#define int long long
long long a[200010];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","r",stdout);
	int n,m,s=0,q=0,x=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(s<a[i]){
			x=i;
		}
		s=max(s,a[i]);	
	}
	
	for(int i=1;i<=n;i++){
		if(i!=x){
			int y=a[i]&s;
			q=max(q,y);
		}
	}
	if(m==1) cout<<s;
	else cout<<q;
	return 0;
}


