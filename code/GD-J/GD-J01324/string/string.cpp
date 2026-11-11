#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e6+10;
struct node{
	int a,c;
};
int n;
int a[maxn];
char c[maxn];
vector<node>g;
signed main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	int sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>c[i];
		sum+=a[i];
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(i==1){
			cnt+=a[i];
			continue;
		} 
		if(c[i]==c[i-1])cnt+=a[i];
		else{g.push_back({cnt,c[i-1]});cnt=a[i];}
	}
	g.push_back({cnt,c[n]});
	n=g.size()-1;
	cnt=0;
	int vis=0;
	if(sum%2==1){
		for(int i=0;i<=n;i++){
			cnt+=g[i].a;
			if(cnt>=(sum/2+1)){
				vis=i;
				break;
			}
		}
	}
	int l=0,r=n;
	int ans=0;
	while(l<=r){
		if(g[l].c==g[r].c){
			if(g[l].a<g[r].a){
				ans+=g[r].a-g[l].a;
				l++;
				r--;
			}else if(g[l].a>g[r].a){
				ans+=g[r].a-g[l].a;
				r--;
				l++;
			}else{
				l++,r--;
			}
		}else{
			if(g[l].a<g[r].a){
				if(sum%2==1&&(l==vis))ans-=1;
				ans+=g[l].a;
				l++;
			}else if(g[l].a>g[r].a){
				if(sum%2==1&&(r==vis))ans-=1;
				ans+=g[r].a;
				r--;
			}else{
				if(sum%2==1&&(r==vis||l==vis))ans-=1;
				ans+=g[l].a;
				l++,r--;
			}
		}
	}
	cout<<ans;
	return 0;
}
