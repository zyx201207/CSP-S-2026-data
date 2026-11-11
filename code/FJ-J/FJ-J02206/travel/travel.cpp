#include<bits/stdc++.h>
using namespace std;
int r,x;
char R[10],X[10]; 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>r>>R>>x>>X;
	if(r==x)cout<<1;
	else cout<<0;
	if(r==x&&R[0]==X[0]&&R[1]==X[1])cout<<1;
	else cout<<0;
	if(r==x&&R[0]==X[0]&&R[1]==X[1]&&((R[2]>='D'&&X[2]>='D')||(R[2]<='C'&&X[2]<='C')))cout<<1;
	else cout<<0;
	if(r==x&&R[0]==X[0]&&R[1]==X[1]&&(R[2]-X[2]==1||X[2]-R[2]==1)&&((R[2]>='D'&&X[2]>='D')||(R[2]<='C'&&X[2]<='C')))cout<<1;
	else cout<<0;
	return 0;
}

