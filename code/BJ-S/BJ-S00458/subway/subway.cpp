#include<bits/stdc++.h>
using namespace std;
bool book[500067]={};
int c,n,m,d,q,w[500067],k[500067];
int a[567][20067],t[567][20067],task[100067][2];
int mindepth=67676767;
void findd(int s,int e,int depth){
}int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)scanf("%d",&w[i]);
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++){
			scanf("%d %d",&a[i][j],&t[i][j]);
		}
	}for(int i=1;i<=q;i++){
		scanf("%d %d",&task[i][0],&task[i][1]);
		findd(task[i][0],task[i][1],0);
		//NONONONONONONONONO
		cout<<67;
	}
	return 0;
}
