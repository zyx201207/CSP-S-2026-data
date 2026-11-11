#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("trevel.out","w",stdout);
	char a[10],b[10],c[10],d[10];
	int ans[4];
	for(int i=0;i<2;i++){
		cin>>a[i];
	}
	for(int i=0;i<3;i++){
		cin>>b[i];
	}
	for(int i=0;i<2;i++){
		cin>>c[i];
	}
	for(int i=0;i<3;i++){
		cin>>d[i];
	}
	if(a==c){
		ans[0]=1;
		}else{
			ans[0]=0;
			}
	if(b[1]==d[1]&&b[0]==d[0]){
		ans[1]=1;
		}else{
			ans[1]=0;
			}
	if(b[2]<='C'&&d[2]<='C'){
		ans[2]=1;
		if(abs(b[2]-d[2])==1){
			ans[3]=1;
			}
			
	}else if(b[2]>'C'&&d[2]>'C'){
		ans[2]=1;
		ans[3]=1;	
	}else{
		ans[2]=0;
		ans[3]=0;
		}
	for(int i=0;i<4;i++){
		cout<<ans[i];
	return 0;
	}
}
