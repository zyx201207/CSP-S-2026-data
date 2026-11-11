#include<bits/stdc++.h>
using namespace std;
char z[10]={'A','B','C','D','F'}; 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	bool f1=0,f2=0,f3=0,f4=0;
	if(c1==c2) f1=1;
	if(f1 && s1[0]==s2[0] && s1[1]==s2[1]) f2=1;
	if(f2){
//		int t1=9,t2=9;
//		for(int i=0;i<5;i++){
//			if(s1[2]==z[i]){
//				if(i<3) t1=0;//abc
//				else t1=1;//df
//			}
//			if(s2[2]==z[i]){
//				if(i<3) t2=0;
//				else t2=1;
//			}
//			if(t1==t2) f3=1;
//		}
		if(s1[2]!='D' && s1[2]!='F' && s2[2]!='D' && s2[2]!='F') f3=1;
		else if(s1[2]!='A' && s1[2]!='B' && s1[2]!='C' && s2[2]!='A' && s2[2]!='B' && s2[2]!='C') f3=1;
	}
	if(f3){
		if(s1[2]=='A' && s2[2]=='C') f4=0;
		else if(s1[2]=='C' && s2[2]=='A') f4=0;
		else if(s1[2]=='C' && s2[2]=='D') f4=0;
		else if(s1[2]=='D' && s2[2]=='C') f4=0;
		else f4=1; 
	}
	cout<<f1<<f2<<f3<<f4;
	return 0;
}
