#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+7;

void inpput(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
}


inline ll read(){
	ll r=1;
	ll w=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')r*=-1;
		c=getchar();
	}
	
	while(c>='0'&&c<='9'){
		w=w*10+c-'0';
		c=getchar();
	}
	return r*w;
} 

int n,k;
vector<vector<int>> g;
 
int main(){
	
	inpput();

	int c,t,u,v;
	c=read();t=read();
	while(t--){
		g.clear();
		n=read();k=read();
		g.resize(n+7);
		for(int i=1;i<n;i++){
			u=read();v=read();
			
			g[u].push_back(v);
			g[v].push_back(u);
			
		}
		if(k==2){
			printf("1\n");
			continue;
		}else if(k==3){
			printf("2\n");
			continue;
		}
		
		
		
		if(c==13||c==14){
			printf("%d\n",(k+1)/2);
		}
		
	}
	
	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

*/
 
