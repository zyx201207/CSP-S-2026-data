#include<bits/stdc++.h>
using namespace std;
char a[3],b[4],c[3],d[4];
int e,f,g,h,m,n,t;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a[1]>>a[2];
	cin>>b[1]>>b[2]>>b[3];
	cin>>c[1]>>c[2];
	cin>>d[1]>>d[2]>>d[3];
	if(a[1]==c[1]&&a[2]==c[2]){
		e=1;
		if(b[1]==d[1]&&b[2]==d[2]){
			f=1,m=int(b[3]-'A'+1),n=int(d[3]-'A'+1);
			if(m>n){
				t=m;
				m=n;
				n=t;
			}
			if((m+n<5||m+n==10)||(m==2&&n==3)){
				g=1;
				if((m==1&&n==2)||(m==2&&n==3)||(m==4&&n==6))h=1;
				else h=0;
			}
			else g=h=0;
		}
		else f=g=h=0;
	}
	else e=f=g=h=0;
	cout<<e<<f<<g<<h<<endl;
	return 0;
}
