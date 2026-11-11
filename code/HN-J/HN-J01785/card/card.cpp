#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	char a[3],b[4],c[3],d[4];
	for(int i=1;i<=2;i++){
		cin>>a[i];
	}
	for(int i=1;i<=3;i++){
		cin>>b[i];
	}
	for(int i=1;i<=2;i++){
		cin>>c[i];
	}
	for(int i=1;i<=3;i++){
		cin>>d[i];
	}
	if(a[1]==c[1]&&a[2]==c[2]){
	   cout<<'1';
	   if(b[1]==d[1]&&b[2]==d[2]){
	   	cout<<'1';
	   	if(b[3]<='C'){
		   if(d[3]<='C'){
		   	cout<<'1';
		   	if(b[3]-d[3]==1||b[3]-d[3]==-1)cout<<'1';
		   	else cout<<"0";
		   }
		   else cout<<"00"; 
	   }
	   else if(b[3]>='D'){
	   	if(d[3]>='D')cout<<"11";
	   	else cout<<"00"; 
	   }
	}
	else cout<<"000";
    }
	else cout<<"0000";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
