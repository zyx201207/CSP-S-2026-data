#include<iostream>
#include<algorithm>
#include<queue>
#include<cstdio>
#include<cmath>	
using namespace std;
string c1,s1,c2,s2;//		continue;
bool x,p,c,l;//车厢，排，同一侧，相邻 
char zd[5]={'A','B','C','D','E'};
bool check(char x){
	int ans=0;
	for(int i=0;i<5;i++){
		if(zd[i]==x){
			ans=i;
		}
	}
	if(0<=ans && ans<=2)return 1;//1在ABC，0在DE 
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		x=1;
		if(s1[0]==s2[0] && s1[1]==s2[1]){
			p=1;
			if(check(s1[2])==check(s2[2])){
				c=1;
				if(abs(s1[2]-s2[2])==1){
					l=1;
				}else{
					l=0;
				}
			}else{
				c=0;
			}
		}else{
			p=0;
		}
	}else{
		x=0;
	}
	cout<<x<<p<<c<<l;
	return 0;
}
