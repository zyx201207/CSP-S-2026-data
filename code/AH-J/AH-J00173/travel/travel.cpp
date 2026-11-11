#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int m=0,M=0,S1,S2;
char n[5]={'A','B','C','D','F'};
int main(){
	freopen("travel.in","r","stdin");
	freopen("travel.out","w","stdout");
	cin>>c1>>s1>>c2>>s2;
	if (c1==c2){
		cout<<1;
		if (s1[0]==s2[0] && s1[1]==s2[1]){
			cout<<1;
			for (int i=0;i<3;i++){
				if (s1[2]==n[i]){
					m++;
					S1=i;
				}
				if (s2[2]==n[i]){
					m++;
					S2=i;
				}
			}
			for (int i=3;i<5;i++){
				if (s1[2]==n[i]){
					M++;
				}
				if (s2[2]==n[i]){
					M++;
				}
			}
			if (m==2 || M==2){
				cout<<1;
				if (M==2){
					cout<<1;
				}
				else if(m==2){
					if (S1-S2==1 || S2-S1==1){
						cout<<1;
					}
					else {
						cout<<0;
					}
				}
			}
			else{
				cout<<0<<0;
			}
			
		}
		else{
			cout<<0<<0<<0;
		}
		
	}
	else{
		cout<<0<<0<<0<<0;
	}
	return 0;
}
