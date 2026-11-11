#include<bits/stdc++.h>
using namespace std;
int n1,n2,s1,s2;
char c1,c2;
int qz[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n1>>s1>>c1>>n2>>s2>>c2;
	if(c2=='F'){
		c2='E';
	}
	if(c1=='F'){
		c1='E';
	}
	if(n1==n2){
		qz[1]=1;
		if(s1==s2){
			qz[2]=1;
			if((c1<='C')==(c2<='C')){
				qz[3]=1;
				if(abs(c1-c2)<=1){
					qz[4]=1;
				}
			}
		}
	}
	for(int i=1;i<=4;i++){
		cout<<qz[i];
	}
	return 0;
}
