#include<bits/stdc++.h>
#define ll long long
//unsigned long long
//priority_queue<int,vector<int>,greater<int>>;
using namespace std;
struct node{
	ll a;
	char c;
}b[200005];
int n;
ll ans,mid,x,y;
queue<node>q;
queue<node>qq;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>b[i].a>>b[i].c;
		mid+=b[i].a;
	}
	mid/=2;
	for(int i=1;x<mid;i++){
		if(x+b[i].a>mid){
			q.push({mid-x,b[i].c});
		}
		else q.push(b[i]);
		x+=b[i].a;
	}
	for(int i=n;y<mid;i--){
		if(y+b[i].a>mid){
			qq.push({mid-y,b[i].c});
		}
		else qq.push(b[i]);
		y+=b[i].a;
	}
	while(qq.size()&&q.size()){
		node f=q.front();
		node g=qq.front();
		if(f.a>g.a){
			qq.pop();
			f.a-=g.a;
			q.front()=f;
			if(f.c!=g.c)ans+=g.a;
		}
		else if(f.a<g.a){
			q.pop();
			g.a-=f.a;
			qq.front()=g;
			if(f.c!=g.c)ans+=f.a;
		}
		else{
			qq.pop();
			q.pop();
			if(f.c!=g.c)ans+=f.a;
		}
	}
	cout<<ans;
	return 0;
}

