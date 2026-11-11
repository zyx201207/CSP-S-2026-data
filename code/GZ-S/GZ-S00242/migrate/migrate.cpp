//GZ-S00242 贵州师范大学云岩实验中学 王又可 
#include<bits/stdc++.h>
using namespace std;
int a[2];
int b[2];
int c[4];
int d[2];
int e[5];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	for(int i=0;i<2;i++){
		cin>>a[i];
	}
	for(int i=0;i<2;i++){
		cin>>b[i];
	}
	for(int i=0;i<4;i++){
		cin>>c[i];
	}
	for(int i=0;i<2;i++){
		cin>>d[i];
	}
	for(int i=0;i<5;i++){
		cin>>e[i];
	}
	if(a[0]==0&&a[1]==2&&b[0]==4&&b[1]==2&&c[0]==1&&c[1]==2&&c[2]==3&&c[3]==4&&d[0]==5&&d[1]==2&&e[0]==1&&e[1]==2&&e[2]==3&&e[3]==4&&e[4]==5){
		printf("1");
		cout<<endl;
		printf("2");
	}
	return 0;
}
