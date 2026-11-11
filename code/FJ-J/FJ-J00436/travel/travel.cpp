#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a1,a2,b1,b2;char a3,b3;
	scanf("%d %2d%c %d %2d%c",&a1,&a2,&a3,&b1,&b2,&b3);
	//cout<<a1<<' '<<a2<<' '<<a3<<' '<<b1<<' '<<b2<<' '<<b3; ok
	if(a1==b1){
		if(a2==b2){
			int t1=a3-'A',t2=b3-'A';
			if((t1<=2&&t2<=2)||(t1>=3&&t2>=3)){
				if(t1-t2==1||t1-t2==-1||(t1==3&&t2==5)||(t1==5&&t2==3)){
					cout<<"1111";
				}else cout<<"1110";
			}else cout<<"1100";
		}else cout<<"1000";
	}else cout<<"0000";
	return 0;
}
