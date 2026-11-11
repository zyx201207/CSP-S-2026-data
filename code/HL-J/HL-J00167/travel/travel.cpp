#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	int c1,c2,n1,n2,b1=0,b2=0,b3=0,b4=0;
	string s1,s2;
	char c[5]={'A','B','C','D','F'};
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<5;i++){
		if(s1[2]==c[i]){
			n1=i;
		}
		if(s2[2]==c[i]){
			n2=i;
		}
	}
	if(c1==c2){
		b1=1;
	}
	if(b1&&s1[0]==s2[0]&&s1[1]==s2[1]){
		b2=1;
	}
	if(b2&&((n1>=0&&n1<=2) && (n2>=0&&n2<=2)) || ((n1>=3&&n1<=4) && (n2>=3&&n2<=4))){
		b3=1;
	}
	if(b3&&((n1==n2+1)||(n1==n2-1))){
		b4=1;
	}
	cout<<b1<<b2<<b3<<b4;
}
