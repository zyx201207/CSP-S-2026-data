#include<bits/stdc++.h>
using namespace std;
int a,b,wt[4];
char a1[3],b1[3];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>a1>>b>>b1;
	if(a==b)wt[0]=1;
	if(wt[0]==1&&a1[0]==b1[0]&&a1[1]==b1[1])wt[1]=1;
	if(wt[0]==1&&wt[1]==1&&a1[2]<='C'&&b1[2]<='C'||wt[0]==1&&wt[1]==1&&a1[2]>='D'&&b1[2]>='D')wt[2]=1;
	if(wt[0]==1&&wt[1]==1&&wt[2]==1&&abs(int(a1[2])-int(b1[2]))==1)wt[3]==1;
	cout<<wt[0]<<wt[1]<<wt[2]<<wt[3];
	return 0;
}
