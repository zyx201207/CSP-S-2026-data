#include<bits/stdc++.h>
using namespace std;
string a;
int c1,c2,s1,s2,ss1,ss2,b[9];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
getline(cin,a);
c1=((a[0]-'0')*10)+(a[1]-'0');
s1=((a[3]-'0')*10)+(a[4]-'0');
ss1=a[5]-'A'+1;	
c2=((a[7]-'0')*10)+(a[8]-'0');
s2=((a[10]-'0')*10)+(a[11]-'0');
ss2=a[12]-'A'+1;
if(c1==c2){
	b[1]=1;
	if(s1==s2){
		b[2]=1;
		if((ss1<=3&&ss2<=3)||(ss1>3&&ss2>3)){
			b[3]=1;
			if((ss1+1==ss2)||(ss1-1)==ss2){
				b[4]=1;
			}
		}
	}
}	
for(int i=1;i<=4;i++){
	cout<<b[i];
}

	return 0;
} 
