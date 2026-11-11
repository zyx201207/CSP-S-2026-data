#include<bits/stdc++.h>
using namespace std;
int t1,t2;
char x[10],y[10],a[10],b[10];
string ans="0000";
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=0;i<2;i++)scanf(" %c",&a[i]);
	for(int i=0;i<3;i++)scanf(" %c",&x[i]);
	for(int i=0;i<2;i++)scanf(" %c",&b[i]);
	for(int i=0;i<3;i++)scanf(" %c",&y[i]);
	if(x[2]>='A'&&x[2]<='C')t1=1;
	if(y[2]>='A'&&y[2]<='C')t2=1;
	if(a[0]==b[0]&&a[1]==b[1]){
		ans[0]='1';
		if(x[0]==y[0]&&x[1]==y[1]){
			ans[1]='1';
			if(t1==t2){
				ans[2]='1';
				if(x[2]+1==y[2]||x[2]-1==y[2])ans[3]='1';
			}
		}
	}else{
		printf("0000");
		return 0;
	}
	cout<<ans;
	return 0;
}
