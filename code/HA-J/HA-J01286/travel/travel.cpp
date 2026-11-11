#include<bits/stdc++.h>
using namespace std;
string r1,r2,x1,x2;
bool ans[5];
int Out(bool b){
	if(b){
		return 1;
	}else{
		return 0;
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>r1>>r2>>x1>>x2;
	ans[1]=r1==x1;
	ans[2]=ans[1]&&(r2[0]==x2[0])&&(r2[1]==x2[1]);
	ans[3]=ans[2]&&((r2[2]<'D')&&(x2[2]<'D'))||((r2[2]>='D')&&(x2[2]>='D'));
	ans[4]=ans[3]&&(r2[2]-x2[2]==1)||(x2[2]-r2[2]==1);
	for(int i=1;i<=4;i++)cout<<Out(ans[i]);
	return 0;
}
