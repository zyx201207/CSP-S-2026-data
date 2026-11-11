#include<bits/stdc++.h>
using namespace std;
int main(){
//	freopen("travel.in","r",stdin);
//	freopen("travel.out","w",stdout);
	char a[3],b[4],c[3],d[4];
	int i=0;
	for(int e=1;e<=2;e++)
		cin>>a[e];
	for(int e=1;e<=3;e++)
		cin>>b[e];
	for(int e=1;e<=2;e++)
		cin>>c[e];
	for(int e=1;e<=3;e++)
		cin>>d[e];
	if(a[1]==c[1]&&a[2]==c[2]){
		cout<<1;
	}else{
		cout<<0<<0<<0<<0;
		i++;
	}
	int s=b[3]-'A'+1,z=d[3]-'A'+1;
	if(((b[1]!=d[1])||(b[2]!=d[2]))&&i==0){
		cout<<0<<0<<0;
		i++;
	}else{
		cout<<1;
	}
	if(((s<=3&&z<=3)||(s>=4&&z>=4))&&i==0){
		cout<<1;
	}else if(((s<=3&&z>=4)||(s>=4&&z<=3))&&i==0){
		cout<<0<<0;
		i++;
	}
	if((s-z==1||z-s==1)&&i==0){
		cout<<1;
	}
	if((s-z>1||z-s>1)&&i==0){
		cout<<0;
	}
	return 0;
}
