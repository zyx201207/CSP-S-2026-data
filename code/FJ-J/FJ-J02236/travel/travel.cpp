#include<bits/stdc++.h>
using namespace std;
struct zw{
	int cx;
	int p;
	string wz;
	int b;
	int c; 
}a[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a[1].cx>>a[1].p>>a[1].wz;
	cin>>a[2].cx>>a[2].p>>a[2].wz;
	if(a[1].wz=="A"||a[1].wz=="B"||a[1].wz=="C")a[1].b=1;
	else a[1].b=2;
	if(a[1].wz=="A")a[1].c=1;
	else if(a[1].wz=="B")a[1].c=2;
	else if(a[1].wz=="C")a[1].c=3;
	else if(a[1].wz=="D")a[1].c=4;
	else if(a[1].wz=="F")a[1].c=5;
	if(a[2].wz=="A"||a[2].wz=="B"||a[2].wz=="C")a[2].b=1;
	else a[2].b=2;
	if(a[2].wz=="A")a[2].c=1;
	else if(a[2].wz=="B")a[2].c=2;
	else if(a[2].wz=="C")a[2].c=3;
	else if(a[2].wz=="D")a[2].c=4;
	else if(a[2].wz=="F")a[2].c=5;
	if(a[1].cx==a[2].cx){
		if(a[1].p==a[2].p){
			if(a[1].b==a[2].b){
				if(abs(a[1].c-a[2].c)==1){
					cout<<1111;
				}else{
					cout<<1110;
				}
			}else{
				cout<<1100;
			}
		}else{
			cout<<1000;
		}
	}else{
		cout<<0000;
	}
	return 0;
} 
