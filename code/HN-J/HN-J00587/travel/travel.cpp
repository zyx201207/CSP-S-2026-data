#include <bits/stdc++.h>
using namespace std;
int b[5];
string c1,c2,c3,c4;
string s,s2;
char a,a2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c1>>c2>>c3>>c4;
	for(int i=0;i<3;i++){
		if(c2[i]>='0'&&c2[i]<='9'){
			s+=c2[i];
		}
		if(c4[i]>='0'&&c4[i]<='9'){
			s2+=c4[i];
		}
	}
	a=c2[2];
	a2=c4[2];
	int b2=0;
	if(c1==c3){
		b[0]=1;
	}
	if(b[0]==1&&s==s2){
		b[1]=1;
	}
	if(b[0]==1&&b[1]==1&&a>='A'&&a<='C'&&a2>='A'&&a2<='C'){
		b[2]=1;
		b2=2;
	}
	else if(b[1]==1&&b[0]==1&&a=='D'&&a2=='F'||a=='F'&&a2=='D'){
		b[2]=1;
		b2=1;
	}
	if(b[2]==1&&(a2==a+1||a2==a-1)&&b2==2||b2==1){
		b[3]=1;
	}
	for(int i=0;i<=3;i++){
		cout<<b[i];
	}
    return 0;
}
