//GZ-J00602 遵义市第四初级中学  彭紫宸 
#include <bits/stdc++.h>
using namespace std;
int cmp(int x,int y){
	return x>y;
}
int f(int x){
	int s=0;
	while(x>0){
		s=10*x%2+s;
		x=x/2;
	}
	return s;
}
int ff(int x){
	int sum=0;
	int ss=1;
	while(x>0){
		sum=sum+x*ss;
		ss=ss*2;
	}
}
int main(){
	freopen("and .in","r",stdin);
	freopen("and .out","w",stdout);
int m,n;
int a[m+5];
int sum=0;
for(int i=1;i<=m;i++){
	cin>>a[i];
}
sort(a+1,a+m,cmp);
int sss=0;
int ssss=0;
int y=0;
for(int i=1;i<=n;i++){
	int ss=f(a[i]);
	
	while(ss>=0){
		
		if(ss%10==0 and sss%10==1){
			ssss=ssss-1*y;
			ss/10;
			sss/10;
		}
		if(y==0){
			y=y+10;
		}
		y=y*10;
	}
}
cout<<ff(ssss);
}
