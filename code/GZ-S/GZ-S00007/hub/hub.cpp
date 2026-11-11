//GZ-S00007 安顺市第一高级中学 徐陈乾康 
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
#define rt return
#define ll long long
const ll MAXN=(ll)1e18+7;
const int ro=(int)2e6+10;

inline int read(){
	int x=0,f=1;
	char c=getchar();
	if(c<'0'||c>'9'){
		if(c=='-'){
			f=-1;
			c=getchar();
		}
	}
	if(c>='0'&&c<='9'){
		x=x*10+(c-'0');
		c=getchar();
	}
	rt x*f;
}

void Sol(){
	
	int n,k,dis1;
	n=read();
	k=read();
	vector<int> u;
	vector<int> v;
	for(int i=0;i<n;i++){
		u[i]=read();
		v[i]=read();
		dis1=(u[i]+v[i])/2;
	}
//	注意到这道题u和v的节点无法输入，放弃 
	cout<<dis1<<'\n';
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	c=read();
	t=read();
	while(t--) Sol();
	rt 0;
}

// 省选/NOI- 
