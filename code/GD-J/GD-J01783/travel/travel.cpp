#include<bits/stdc++.h>
using namespace std;
int a,b,ans[5];
string x,y;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	memset(ans,0,sizeof(ans));
	scanf("%d",&a); cin>>x;
	scanf("%d",&b); cin>>y;
	if(a==b){
		ans[1]=1;
		if(x[0]==y[0]&&x[1]==y[1]){
			ans[2]=1;
			if(('A'<=x[2]&&x[2]<='C'&&'A'<=y[2]&&y[2]<='C')||('D'<=x[2]&&x[2]<='F'&&'D'<=y[2]&&y[2]<='F')){
				ans[3]=1;
				if(x[2]+1==y[2]||x[2]==y[2]+1){
					ans[4]=1;
				}
			}
		}
	}
	printf("%d%d%d%d",ans[1],ans[2],ans[3],ans[4]);
	return 0;
} 
