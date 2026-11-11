#include<bits/stdc++.h>

using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int cnt=0;
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int n1=(s1[0]-'0')*10+s1[1]-'0';
	int n2=(s2[0]-'0')*10+s2[1]-'0';
	char n=s1[2],m=s2[2];
	if(c1==c2){
		cnt++;
		if(n1==n2){
			cnt++;
			if((n<='C'&&m<='C')||(n>='D'&&m>='D')){
				cnt++;
				if(!(n=='C'&&m=='D')&&!(n=='D'&&m=='C')&&(n-m==1||m-n==1)){
					cnt++;
				}
			}
		}
	}for(int i=1;i<=cnt;i++){
		cout<<1;
	}for(int i=1;i<=4-cnt;i++){
		cout<<0;
	}
	return 0;
}
