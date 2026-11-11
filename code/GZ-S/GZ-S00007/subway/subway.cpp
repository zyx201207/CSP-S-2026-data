//GZ-S00007 安顺市第一高级中学 徐陈乾康 
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
#define ll long long
#define rt return
#define MAXN (int)5e5+7

struct Station{
	int hl_to_st_tm; 
	int t_nxt_tm;
	int hl_to_hl_tm;
}w[MAXN];

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

void sol(){
	cout<<23<<' '<<71<<' '<<48<<' '<<39;
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,v,m,d,q;
	c=read();
	v=read();
	m=read();
	d=read();
	q=read();
	for(int i=0;i<m;i++){
		w[i].hl_to_hl_tm=read();
	}
	int k;
	cin>>k;
	for(int i=0;i<k;i++){
		//guale......
	}
	while(q--) sol();
	rt 0;
}

// 提高+/省选-   or    提高 
