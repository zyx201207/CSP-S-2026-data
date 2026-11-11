#include <bits/stdc++.h>
using namespace std;
int n;string s;
struct sk{
	int gd;
	char aa;
};
sk p[200020];
main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>p[i].gd>>p[i].aa;
	}
	int l=1,r=n;long long ans=0;
	while(l<r){
		int ss=0;
		if(p[l].aa==p[r].aa){
			ss=min(p[l].gd,p[r].gd);
			p[l].gd-=ss;
			p[r].gd-=ss;
		}
		else{
			ss=min(p[l].gd,p[r].gd);
			p[l].gd-=ss;
			p[r].gd-=ss;
			ans+=ss;
		}
		if(p[l].gd==0) l++;
		if(p[r].gd==0) r--;
	}
	cout<<ans;
	return 0;
} 
