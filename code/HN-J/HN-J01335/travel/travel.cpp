#include<bits/stdc++.h>
using namespace std;
string s1,s2,y="ABCDE";
int c1,c2,sum[4];
int a[18][5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		sum[0]=1;
		int k1=(s1[0]-'0')*100+(s1[1]-'0')*10;
		for(int i=0;i<5;i++){
			if(s1[2]==y[i]){
				k1+=i+1;
			}
		}
		int k2=(s2[0]-'0')*100+(s2[1]-'0')*10;
		for(int i=0;i<5;i++){
			if(s2[2]==y[i]){
				k2+=i+1;
			}
		}
		if(k1/10==k2/10){
			sum[1]=1;
			if(k1%10<=3&&k2%10<=3||k1%10>3&&k2%10>3){
				sum[2]=1;
				if(k1%10+1==k2%10||k1%10-1==k2%10){
					sum[3]=1;
				}
			}
		}
	}
	for(int i=0;i<4;i++){
		cout<<sum[i];
	}
	return 0;
} 
