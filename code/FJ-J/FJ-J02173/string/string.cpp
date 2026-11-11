#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

struct node{
	long long a;
	char c;	
}node[200005];

// kai long long
// scanf printf %lld

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	scanf("%d",&n);
	int cnt=0;
	for(int i=1;i<=n;i++){
		++cnt;
		cin>>node[cnt].a>>node[cnt].c;
		if(node[cnt].c==node[cnt-1].c){
			node[cnt-1].a+=node[cnt].a;
			node[cnt].a=0;
			node[cnt].c=0;
			cnt--;
		}
	}
	int l=1,r=cnt;
	long long minx=0;
	long long sum=0;
	while(l<=r){
		minx=min(node[l].a,node[r].a);
		if(node[l].c!=node[r].c) sum+=minx;
		node[l].a-=minx;
		node[r].a-=minx;
		if(node[l].a<=0) l++;
		if(node[r].a<=0) r--;
	}
	printf("%lld",sum);
}