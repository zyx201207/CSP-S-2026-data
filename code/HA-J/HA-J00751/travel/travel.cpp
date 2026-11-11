#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int sum;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3){
		sum++;
		if(s2[0]==s4[0]&&s2[1]==s4[1]){
			sum++;
			char c1=s2[2],c2=s4[2];
			if((c1>='A'&&c2<='C')||(c1>='D'&&c2<='E')){
				sum++;
				if(abs(c1-c2)==1) sum++;
			}
		}
	}
	for(int i=1; i<=4; i++){
		if(sum) cout<<1,sum--;
		else cout<<0;
	}
	return 0;
}
