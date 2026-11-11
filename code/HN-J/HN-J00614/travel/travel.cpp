#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	int len1=s1.size(),len2=s2.size(),len3=s3.size(),len4=s4.size();
	int sum1=0,sum3=0;
	for(int i=0;i<len1;i++){
		sum1=sum1*10+(s1[i]-'0');
	}for(int i=0;i<len3;i++){
		sum3=sum3*10+(s3[i]-'0');
	}
	int sum2=0,sum4=0;
	char a=s2[len2-1],b=s4[len4-1];
	for(int i=0;i<len2-1;i++){
		sum2=sum2*10+(s2[i]-'0');
	}for(int i=0;i<len4-1;i++){
		sum4=sum4*10+(s4[i]-'0');
	}
	if(sum1==sum3){
		cout<<1;
		if(sum2==sum4){
			cout<<1;
			if((a=='D'||a=='F')&&(b=='D'||b=='F')||(a=='A'||a=='B'||a=='C')&&(b=='A'||b=='B'||b=='C')){
				cout<<1;
				if(abs(int(a-b))==1){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<0<<0;
			}
		}
		else cout<<0<<0<<0;
	}
	else cout<<0<<0<<0<<0;
	return 0;
}
