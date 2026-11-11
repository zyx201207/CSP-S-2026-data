#include<bits/stdc++.h>
using namespace std;
int c1,c2,p1,p2;
char s1,s2; 
int x[]={1,1,1,2,2};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>p1>>s1>>c2>>p2>>s2;
	if(c1!=c2){
		cout<<"0000";
	}else if(p1!=p2){
		cout<<"1000"; 
	}else{
		if(x[s1-'A']!=x[s1-'A']){
			cout<<"1100";
		}else if(abs(s1-s2)==1&&max(s1,s2)!='D'){
			cout<<"1111"; 
		}else cout<<"1110";
	}
	return 0;
}
 
