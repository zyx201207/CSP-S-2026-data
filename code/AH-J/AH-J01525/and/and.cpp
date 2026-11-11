#include<bits/stdc++.h>
using namespace std;
int a[200005],v[200005],p=1<<30,s,ans,n,m;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	while(p>0){
		s=0;
		for(int i=1;i<=n;i++){
			if(!v[i]&&p&a[i]) s++;
		}
		if(s>=m){
			ans=ans|p;
			for(int i=1;i<=n;i++){
				if(!(p&a[i])) v[i]=1;
			}
		}
		p=p>>1; 
	}
	cout<<ans;
	return 0;
} 
