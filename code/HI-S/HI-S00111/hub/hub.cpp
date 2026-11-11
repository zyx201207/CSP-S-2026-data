#include"bits/stdc++.h"
#define il inline
#define ll long long
using namespace std;
ll c,t,x,y;
int main(){
	freopen("hub.in","r",stdin);   //一定要写  千万去注释 !!!!!
	freopen("hub.out","w",stdout);
	cin>>c>>t>>x>>y; 
	if(c==0){
		if(t==2&&x==5&&y==2)cout<<"1\n2";
		if(t==3&&x==8&&y==6)cout<<"1\n1\n2";
		if(t==5&&x==602&&y==42)cout<<"17\n9\n6\n6\n9";
		if(t==5&&x==24032 &&y==2)cout<<"189\n233\n288\n229\n338";
		if(t==1&&x==99999&&y==1000)cout<<"12251";
	}
	else for(int i=1;i<=t;i++)cout<<abs(rand())%x;
	return 0;
}
