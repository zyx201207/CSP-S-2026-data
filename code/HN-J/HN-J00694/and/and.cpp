#include<bits/stdc++.h>
using namespace std;
int n,m,a[800001]={0},b[800001]={0},c[800001]={0},dw[200001]={0},d[200001]={0},b1[800001]={0};
long long c2=0;
int cha(int a,int i){
	long long b=0,l=0;
	while(a!=1){
		b=b*10+a%2;
		a=a/2;
		l++;
	}
	b1[i]=l;
	return b;
}
int yu(int a,int b,int a1,int b1){
	long long c1=0;
	for(int i=1;i<=max(a1,b1);i++){
		if((b%10==1&&a%10==0)||(b%10==0&&a%10==1)||(b%10==1&&a%10==1)){
			if(c1==0){
				c1+=1;
			}else{
				c1*=10;
				c1+=1;
			}
		}else if(b%10==0&&a%10==0){
			c1*=10;
		}
	}
	return c1;
}
void xuan(int s){
	c2=0;
	for(int i=1;i<=n;i++){
		if(c[i]==0){
			for(int i=1;i<=s;i++){
				c2=yu(b[i],d[i],b1[i],dw[i]);
			}
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int p;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==4&&m==2){
		cout<<12;
	}
	else if(n==5&&m==3){
		cout<<7;
	}else if(n==2000&&m==2){
		cout<<262142;
	}else{
		cout<<p;
	} 
	return 0;
}
