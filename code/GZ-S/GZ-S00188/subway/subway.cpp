/*GZ-S00188 贵阳市第二实验中学 莫卓均*/ 
#include<bits/stdc++.h>
using namespace std;
struct node{
	int station,time;
}s[501][3];
struct Node{
	int begin,end;
}travel[100001];
int n,m,d,q,t,d1[21],x,y,s1[501],z;
void aaa(int a,int b){
	if(a==b){
		x=min(x,y);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(s[n][1].station==a){
			y+=s[i][1].time;
			aaa(s[i][1].station,b);
			y-=s[i][1].time; 
		}
		else if(s[n][2].station==a){
			y+=s[i][2].time;
			aaa(s[i][2].station,b);
			y-=s[i][2].time; 
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d %d %d %d %d",&t,n,m,d,q);
	for(int i=1;i<=d;i++){
		scanf("%d",&d1[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&s1[i]);
		for(int j=1;j<=s1[i];j++){
			scanf("%d %d",&s[i][j].station,s[i][j].time);
		}
	}
	for(int i=q;i<=d;i++){
		scanf("%d %d",&travel[i].begin,travel[i].end);
	}
	x=*max_element(s1+1,s1+n+1);
	for(int i=1;i<=q;i++){
		y+=d1[i];
		y-=s[i][1].time;
		aaa(travel[i].begin,travel[i].end);
	}
	return 0;
}
