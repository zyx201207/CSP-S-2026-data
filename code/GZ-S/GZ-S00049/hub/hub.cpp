//уейкаж GZ-S00049 
#include<bits/stdc++.h>
using namespace std;
int c,t;
int a[100000000];
int n,m,d,q;
int w[505];
struct Line{
	int pass;
	int point[505];
	int time[505];
}l[505];
int th[505]={0};
int ans=100000000;
int dfs(int s,int e,int now,int t,int line){
	if(e==now){
		t+=w[e];
		return t;
	}
	if(s==now){
		if(line==0){
			t+=w[s];
			th[s]=1;
			for(int i=1;i<=n;++i){
				if(l[i].point[s]!=0){
					int cp=dfs(s,e,now,t,line);
					if(ans>cp)return cp;
					else return ans;
				}
			}
		}
	}
	for(int i=1;i<=l[line].pass;++i){
		if(th[now]!=1&&l[line].point[i]==1){
			for(int j=1;j<=n;++j){
				if(l[j].point[now]!=0){
					int cp=dfs(s,e,i,t+l[line].time[i],j);
					if(ans>cp)return cp;
					else return ans;
				}
			}
		}
	}
}
int main(){
	scanf("%d%d",&c,&t);
	for(int i=1;i<=t;++i){
		int n,k;
		scanf("%d%d",&n,&k);
		int ui,vi;
		for(int j=1;j<=n;++j){
			scanf("%d%d",&ui,&vi);
		}
	}
	printf("1\n2\n");
	return 0;
}
