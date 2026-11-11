#include<bits/stdc++.h> 
using namespace std;
int a[3],b[3];int f1,f2,f3,f4;
char c[3];
int change(char a,char b){
	int sum=0;
	sum=sum+(a-'0');
	sum*=10;
	sum=sum+(b-'0');
	return sum;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string z;
	int c1;
	for(int i=1;i<=2;i++){
		cin>>c1;
		a[i]=c1;
		cin>>z;
		b[i]=change(z[0],z[1]);
		c[i]=z[2];
	}
	if(a[1]==a[2]){
		f1=1;
		if(b[1]==b[2]){
			f2=1;
			if(c[1]>='A' and c[1]<='C' and c[2]>='A' and c[2]<='C'){
				f3=1;
				if(c[1]-c[2]==1 or c[1]-c[2]==-1){
					f4=1;
				}
			}
			else if(c[1]>='D' and c[1]<='F' and c[2]>='A' and c[2]<='F'){
				f3=1;
				f4=1;
			}
		}
	}
	
	
	cout<<f1<<f2<<f3<<f4;
	return 0;
}
/* 两张车票对应的座位是否在同一节车厢；
 两张车票对应的座位是否在同一节车厢的同一排；
 两张车票对应的座位是否在同一节车厢的同一排，且位于过道的同一侧；
 两张车票对应的座位是否相邻。*/
