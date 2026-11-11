#include<bits/stdc++.h>
using namespace std;
int const N=100010;
struct ticket{
	int chx;
	int p=0;
	int h;
}a[3]; 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=1;i<=2;i++){
		string s;
		scanf("%d",&a[i].chx);
		cin>>s;
		for(int j=0;j<2;j++){
			a[i].p=a[i].p*10+(s[j]-'0');
		}
		a[i].h=s[2]-'A'+1;
		//cout<<a[i].chx<<" "<<a[i].p<<a[i].h<<endl;
	}
	if(a[1].chx==a[2].chx){
		printf("1");
	}else{
		printf("0000");
		return 0;
	}
	if(a[1].p==a[2].p){
		printf("1");
	}else{
		printf("000");
		return 0;
	}
	if((abs(a[1].h-a[2].h)<=2)&&!((a[1].h==3&&a[2].h==4)||(a[1].h==4&&a[2].h==3))){
		printf("1");
	}else{
		printf("00");
		return 0;
	}if(abs(a[1].h-a[2].h)==1){
		printf("1");
		return 0;
	}
	printf("0");
	return 0;
}
