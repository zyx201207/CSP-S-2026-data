#include<bits/stdc++.h>
using namespace std;
int c1[16];
int s1[18];
int c2[16];
int s2[18];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    int c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    int A=1,B=2,C=3,D=4,F=5;
    if(c1==c2){cout<<'1';}
    else{cout<<'0';}
	if(s1==s2){cout<<'1';}
    else{cout<<'0';}
    for(int j;j>=1,j<=5;i++){
    if(s1[j]==3,s2[j]==4 && s1[j]==4,s2[j]==3) cout<<'0';
    else cout<<'1';
    return 0;}
   	for(int j;j>=1,j<=5;i++){
    if(s1[j]==s2[i][j+1] || s1[j]==s2[i][j-1]) cout<<'1';
    else cout<<'0';
    return 0;}
    return 0;
}