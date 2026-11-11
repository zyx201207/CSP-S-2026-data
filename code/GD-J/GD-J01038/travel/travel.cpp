#include<bits/stdc++.h>
using namespace std;
string c1,c2,x1,x2;
int sum,l,r,c;
char a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>x1>>c2>>x2;
	l=(x1[0]-'0')*10+(x1[1]-'0');
	r=(x2[0]-'0')*10+(x2[1]-'0');
	a=x1[2];
	b=x2[2];
	if(c1==c2){
		sum++;
		if(l==r){
			sum++;
			if(!((a=='C'&&b=='D')||(a=='D'&&b=='C'))){
				sum++;
				if(abs(a-b)==1){
					sum++;
				}
			}
		}
	}for(int i=1;i<=4;i++){
		if(sum>0){
			sum--;
			cout<<1;
		}else cout<<0;
	}
	return 0;
} 
