#include<bits/stdc++.h>
using namespace std;
char a[5],b[5],c[5],d[5];
bool ans[10];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a[0]==c[0]&&a[1]==c[1]){
		ans[1]=1;
		if(b[0]==d[0]&&b[1]==d[1]){
			ans[2]=1;
			if((b[2]<='C'&&d[2]<='C')||(b[2]>='D'&&d[2]>='D')){
				ans[3]=1;
				if(!((b[2]=='A'&&d[2]=='C')||(b[2]=='C'&&d[2]=='A'))){
					ans[4]=1;
				}
			}
		}
	}
	for(int i=1;i<=4;i++)cout<<ans[i];
	return 0;
}
