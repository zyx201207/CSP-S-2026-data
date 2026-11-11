#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int c1,c2,c3,c4,ans[4];
char c2c,c4c;
int main(){
	freopen("travel.in","r",stdin);
	/*提交时去掉freopen！！！*/
	freopen("travel.out","w",stdout);

	memset(ans,0,sizeof(ans));
	scanf("%d %d%c %d %d%c",&c1,&c2,&c2c,&c3,&c4,&c4c);
	//printf("%d %d %c %d %d %c\n",c1,c2,c2c,c3,c4,c4c);
	if(c1==c3)ans[0]=1;

	if(ans[0]&&c2==c4)ans[1]=1;

	if(ans[0]&&ans[1]){
		if('A'<=c2c&&c2c<='C'&&'A'<=c4c&&c4c<='C')ans[2]=1;
		if((c2c=='D'||c2c=='F')&&(c4c=='D'||c4c=='F'))ans[2]=1;

		if(c2c=='A'&&c4c=='B')ans[3]=1;
		if(c2c=='B'&&(c4c=='C'||c4c=='A'))ans[3]=1;
		if(c2c=='C'&&c4c=='B')ans[3]=1;
		if(c2c=='D'&&c4c=='F')ans[3]=1;
		if(c4c=='A'&&c2c=='B')ans[3]=1;
		if(c4c=='B'&&(c2c=='C'||c2c=='A'))ans[3]=1;
		if(c4c=='C'&&c2c=='B')ans[3]=1;
		if(c4c=='D'&&c2c=='F')ans[3]=1;
	}

	for(int i=0;i<4;i++)printf("%d",ans[i]);
	printf("\n");
	return 0;
}
/*提交时去掉freopen！！！*/
