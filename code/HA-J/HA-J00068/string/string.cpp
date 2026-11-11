#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,cnt,ans;
pair<int,int>p[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		c=c-'a'+1;
		cnt+=a;
		p[i]=(pair<int,int>){a,c};
	}
	int l=1,r=n,l1=0,r1=0,now=0,len=0;
	while(l<=r){
		if(l1<=r1){
			pair<int,int>p1=p[l];
			int u=p1.first,v=p1.second;
			l++;
			if(l1+u>=r1){
				if(now!=v&&now!=0){
					ans+=len;
				}
				len=u-len;
				now=v;
			}
			else{
				if(now!=v&&now!=0){
					ans+=u;
				}
				len-=u;
			}
			l1+=u;
		}
		else{
			pair<int,int>p1=p[r];
			int u=p1.first,v=p1.second;
			r--;
			if(r1+u>=l1){
				if(now!=v&&now!=0){
					ans+=len;
				}
				len=u-len;
				now=v;
			}
			else{
				if(now!=v&&now!=0){
					ans+=u;
				}
				len-=u;
			}
			r1+=u;
		}
	}
	cout<<ans;
	return 0;
}
