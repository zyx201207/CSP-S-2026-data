#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1005];
int len;
bool x(int a,int b){
	return a>b;
}
int turn(int n){//进制转换 
	int i=1;
	int s=0;
	while(n>0){
		s+=n%2*i;
		i*=10;
		n/=2;
		
	}
	return s;
}
int and_(int a,int b){//与运算 
	int c[1005];
	int lena=0,lenb=0;
	int a1=a,b1=b;
	while(a1>0){
		a1/=10;
		lena++;
	}
	while(b1>0){
		b1/=10;
		lenb++;
	}
	int x[1005]={0},y[1005]={0};
	for(int i=1;i<=lena;i++){
		x[i]=a%10;
		a/=10;
	}
	for(int i=1;i<=lenb;i++){
		y[i]=b%10;
		b/=10;
	}
//	for(int i=1;i<=lena;i++){
//		cout<<x[i];
//	}	
//	cout<<"\n";
//	for(int i=1;i<=lenb;i++){
//		cout<<y[i];
//	}
//	cout<<"\n";
	int len=max(lena,lenb);
	for(int i=1;i<=len;i++){
		if(x[i]==y[i])c[i]=1;
	}
	int ans=0;
	for(int i=1;i<=len;i++){
		for(int j=1;j<=i-1;j++){
			c[i]*=2;
		}
	}
	for(int i=1;i<=len;i++){
		ans+=c[i];
	}
	return ans;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,x);
	int x,y;
	x=a[1];
	for(int i=2;i<=m;i++){
		y=a[i];
		x=and_(turn(x),turn(y));
	}
	cout<<x; 

//cout<<turn(10);
	return 0;
}

