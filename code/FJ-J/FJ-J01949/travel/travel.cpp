#include<bits/stdc++.h>
using namespace  std;

struct in{
	string age;
	string sum;	
}a,b;

int f(){
	int h=a.sum[2]-b.sum[2];
	h=abs(h);
	if(h==1){
		return 1;
	}
	return 0;
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a.age>>a.sum>>b.age>>b.sum;
	if(a.age==b.age){
		if(a.sum[0]==b.sum[0] && a.sum[1]==b.sum[1]){
			if(a.sum[2]>='A' && a.sum[2]<='C'){
				if(b.sum[2]>='A' && b.sum[2]<='C'){
					if(f()==1){
						cout<<1111;
					}else{
						cout<<1110;
					}
				}else{
					cout<<1100;
				}
			}else{
				if(b.sum[2]>='D' && b.sum[2]<='F'){
					cout<<1111;
				}else{
					cout<<1100;
				}
			}
		}else{
			cout<<"1000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
