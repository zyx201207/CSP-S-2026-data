#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	long long a=(s1[0]-'0')*10+s1[1]-'0',b=(s3[0]-'0')*10+s3[1]-'0',c=(s2[0]-'0')*10+s2[1]-'0',d=(s4[0]-'0')*10+s4[1]-'0';   //a£¨b±Ì æ≥µœ·
	char c1=s2[2],d1=s4[2];
	if(a==b){
		cout<<1;
		if(c==d){
			cout<<1;
			if((c1=='A'||c1=='B'||c1=='C')&&(d1=='A'||d1=='B'||d1=='C')){
				cout<<1;
				if(abs(int(c1-d1))==1){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<00;
			}
		}else{
			cout<<000;
		}
	}else{
		cout<<0000;
	}
	return 0;
} 
