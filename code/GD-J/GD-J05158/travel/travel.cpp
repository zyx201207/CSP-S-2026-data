#include<bits/stdc++.h>
using namespace std;
int a[4];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		a[0]=1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			a[1]=1;
			int z=(int)(s1[2]-'A'),b=(int)(s2[2]-'A');
			if((z<=2&&b<=2)||(z>=3&&b>=3)){
				a[2]=1;
				int ans=z-b;
				if(ans<0){
					ans=-ans;
				}
				if(ans==1){
					a[3]=1;
				}
				else if(z==3&&b==5||z==5&&b==3){
					a[3]=1;
				}
			}
		}
	}
	for(int i=0;i<=3;i++){
		cout<<a[i];
	} 
	return 0;
} 
