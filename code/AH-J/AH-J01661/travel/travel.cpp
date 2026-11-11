#include<bits/stdc++.h>
using namespace std;
char a,a1,b,b1,a2,a3,a4,b2,b3,b4;
int cnt=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>a1>>a2>>a3>>a4;
	cin>>b>>b1>>b2>>b3>>b4;
	if(a==b&&a1==b1){
		cnt+=1;
		if(a2==b2&&a3==b3){
			cnt+=1;
			if((a4<='C'&&b4<='C')||(a4>='D'&&b4>='D')){
				cnt+=1;
				if(abs((int)a4-(int)b4)==1){
					cnt+=1;
				}
			}
		}
	}
	for(int i=1;i<=4;i++){
		if(cnt>0){
			cout<<1;
			cnt-=1;
		}
		else {
			cout<<0;
		}
	}
	return 0;
}
