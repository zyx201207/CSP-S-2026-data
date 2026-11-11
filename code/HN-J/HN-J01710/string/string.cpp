#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=1e6+5;
int n,a[M],s[M],b[M];
char c[M],c1[M];
struct Node{
	int a;
	char b;
};
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		s[i]=s[i-1]+a[i];
	}
	int ans=0;
	if(s[n]&1){
		int k=s[n]/2+1;
		int res=-1;
		for(int i=1;i<=n;i++){
			if(s[i]>=k){
				res=i;
				break;
			}
		}
		int cnt=0,p=0;
		stack<Node>q;
		for(int i=1;i<=res;i++){
			if(s[i]>=k){
				b[++cnt]=k-1-s[i-1];
				c1[cnt]=c[i];				
			}
			else{
				b[++cnt]=a[i];
				c1[cnt]=c[i];
			}
		}
		for(int i=1;i<=cnt;i++){
			q.push({b[i],c1[i]});
		}
		int u=0;
		if(s[res]==k){
			u++;
		}
		for(int i=res+u;i<=n;i++){
			int o=0;
			if(i==res){
				o=s[res]-k;
			}
			else{
				o=a[i];
			}
			while(!q.empty()&&o>=q.top().a){
				if(c[i]!=q.top().b){
					ans+=q.top().a;
				}
				o-=q.top().a;
				q.pop();
			}
			if(!q.empty()&&o<q.top().a){
				int g=q.top().a-o;
				char y=q.top().b;
				if(y!=c[i]){
					ans+=o;
				}
				q.pop();
				q.push({g,y});
			}
		}
		cout<<ans<<'\n';
	}
	else{
		int k=s[n]/2;
		int res=-1;
		for(int i=1;i<=n;i++){
			if(s[i]>=k){
				res=i;
				break;
			}
		}
		int cnt=0,p=0;
		stack<Node>q;
		for(int i=1;i<=res;i++){
			if(s[i]>=k){
				b[++cnt]=k-1-s[i-1];
				c1[cnt]=c[i];				
			}
			else{
				b[++cnt]=a[i];
				c1[cnt]=c[i];
			}
		}
		for(int i=1;i<=cnt;i++){
			q.push({b[i],c1[i]});
		}
		k++;
		int u=0;
		if(s[res]==k){
			u++;
		}
		for(int i=res+u;i<=n;i++){
			int o=0;
			if(i==res){
				o=s[res]-k;
			}
			else{
				o=a[i];
			}
			while(!q.empty()&&o>=q.top().a){
				if(c[i]!=q.top().b){
					ans+=q.top().a;
				}
				o-=q.top().a;
				q.pop();
			}
			if(!q.empty()&&o<q.top().a){
				int g=q.top().a-o;
				char y=q.top().b;
				if(y!=c[i]){
					ans+=o;
				}
				q.pop();
				q.push({g,y});
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
