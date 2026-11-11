#include<bits/stdc++.h>
using namespace std;
int a[500010];
int s[500010];
int n,m;
bool f(int x){
	for(int i=1;i<=n-x+1;i++){
		int end=i+x-1;
		int sum=-s[i-1]+s[end-1];
		int dif=a[end]*(x-1)-sum;
		if(dif<=m){
			return 1;
		} 
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i]; 
	}
	int l=1,r=n;//[l,r]; 
	while(l<r){
		int x=(l+r+1)/2;
		if(f(x)){
			l=x;
		}
		else{
			r=x-1;
		}
	//	cout<<l<<' '<<r<<endl;
	}
	cout<<l;
} 
/*
!?fx?!
//GoC
#include<bits/stdc++.h>
using namespace std;
int main(){
pen.down();showXY();
   freopen("fx.txt","w",stdout);
   pen.rt(180);
   pen.size(1);
	srand(time(0));
	double price=1;
	double t=-400;
	double suofang=1;
	pen.move(t,price*suofang-200);  
	double x=0;
	while(1){
		double tt=((rand()%200));
		if(tt>90+x){
			tt=(tt-90-x)*0.1/(110-x);
			x+=1.01;
		}
	else{
		x--;
		tt=(tt-110+x)*0.1/(90+x);
	}
	tt++;
		price*=tt;
		if(tt>1){
			printf("+");
     pen.color(_red);
		}
		else{
			
     pen.color(_green);
		}
		printf("%lf% ",((tt-1)*100));
		printf("  %lf\n",price);
		Sleep(10);
		t++;
		if(price<0.01){
			return 0;
		}
	pen.line(pen.getX(),price*suofang);  
	if(pen.getX()>400){
	t=00;
	pen.cls();showXY();
	pen.move(00,price*suofang);
	}
	while(pen.getY()>200){
		suofang/=2;
	pen.cls();showXY();
	pen.move(00,price*suofang);
	}
	while(pen.getY()<50){
		suofang*=2;
	pen.cls();showXY();
	pen.move(00,price*suofang);
	}
	pen.move(pen.getX()+1,price*suofang);
	}
}
*/ 
