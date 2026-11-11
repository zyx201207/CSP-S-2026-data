#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
char a[8]={'0','0','0','0','0'};
int C1,S1,C2,S2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	C1=c1.length();
	C2=c2.length();
	S1=s1.length();
	S2=s2.length();
	if(C1==C2){
		for(int i=0;i<C1;i++){
			if(c1[i]==c2[i]){
				a[1]='1';
			}
			else{
				a[1]='0';
			}
		}
	}
	if(a[1]=='1'){
		if(S1==S2){
			for(int i=0;i<S1-1;i++){
				if(s1[i]==s2[i]){
					a[2]='1';
				}
				else{
					a[2]='0';
				}
			}
			if((s1[S1-1]>='D'&&s2[S2-1]>='D'&&a[2]=='1')||(s1[S1-1]<='C'&&s2[S2-1]<='C'&&a[2]=='1')){
				a[3]='1';
				if(abs(int(s1[S1-1])-int(s2[S2-1]))==1||(s1[S1-1]=='D'&&s2[S2-1]=='F')||(s1[S1-1]=='F'&&s2[S2-1]=='D')){
					a[4]='1';
				}
			}
		}
	}
	for(int i=1;i<=4;i++){
		cout<<a[i];
	}
	return 0;
}
