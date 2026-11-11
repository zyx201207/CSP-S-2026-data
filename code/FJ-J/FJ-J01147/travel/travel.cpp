#include <bits/stdc++.h>
using namespace std;
array<int,3> id[2];
void solve(){
	for(int i=0;i<2;i++){
		char ch=getchar();
		while(ch<'0'||'9'<ch)
			ch=getchar();
		id[i][0]=id[i][0]*10+(ch-'0');

		ch=getchar();
		while(ch<'0'||'9'<ch)
			ch=getchar();
		id[i][0]=id[i][0]*10+(ch-'0');
		
		ch=getchar();
		while(ch<'0'||'9'<ch)
			ch=getchar();
		id[i][1]=id[i][1]*10+(ch-'0');

		ch=getchar();
		while(ch<'0'||'9'<ch)
			ch=getchar();
		id[i][1]=id[i][1]*10+(ch-'0');	
		
		ch=getchar();
		while(ch<'A'||'Z'<ch)
			ch=getchar();
		id[i][2]=(ch-'A');	
	}
	if(id[0][0]!=id[1][0])
		printf("0000");
	else if(id[0][1]!=id[1][1])
		printf("1000");
	else if((id[0][2]<3)!=(id[1][2]<3))
		printf("1100");
	else if(abs(id[0][2]-id[1][2])>1&&id[0][2]!=5&&id[1][2]!=5)
		printf("1110");
	else
		printf("1111");
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int T=1;
//	scanf("%d",&T);
	for(;T;T--) solve();
}
