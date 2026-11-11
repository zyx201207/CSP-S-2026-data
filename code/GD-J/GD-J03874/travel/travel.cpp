#include<iostream>
using namespace std;
int main(){
	preopen("travel.in","r",stdin);
	preopen("travel.out","w",stdout);
	int a,b,c=4,n,m;
	char a1[100],b1[100];
	cin>>a;
	for(int i=1;i<=3;i++){
	cin>>a1[i];
	}
	cin>>b;
	for(int i=1;i<=3;i++){
	cin>>b1[i];
	}
	if(a1[3]>b1[3]){
		n=a1[3];
		m=b1[3];
	}
	else{
		n=b1[3];
		m=a1[3];
	}
	if(a==b){
		c=c-1;
		if(a1[1]==b1[1]&&a1[2]==a1[2]){
			c=c-1;
			if(n==m+1){
				c=c-2;
			}
		}
	}
	for(int i=1;i<=4-c;i++){
		cout<<1;
	}
	for(int i=1;i<=c;i++){
		cout<<0;
	}
	return 0;
}
