#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
long long a1,a2;
long long sum=4;
long long w=0000;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	a1=s1[0]*10+s1[1];
	a2=s2[0]*10+s2[1];
	if(c1==c2){
		w+=1000;
		sum--;
	}
	if(c1==c2 && a1==a2){
		w+=100;
		sum--;
	}
	if(c1==c2 && a1==a2){
		if(s1[2]=='A' || s1[2]=='B' || s1[2]=='C'){
			if(s2[2]=='A' || s2[2]=='B' || s2[2]=='C'){
				w+=10;
				sum--;
			}
		}
		if(s1[2]=='D' || s1[2]=='F'){
			if(s2[2]=='D' || s2[2]=='F'){
				w+=10;
				sum--;
			}
		}
	}
	if(c1==c2){
		if(((s1[2]=='A' || s1[2]=='B' || s1[2]=='C') && s2[2]=='A' || s2[2]=='B' || s2[2]=='C') || ((s1[2]=='D' || s1[2]=='F') && s2[2]=='D' || s2[2]=='F')){
			if(a1+1==a2 && s1[2]==s2[2]){
				w+=1;
				sum--;
			}
			if(a1-1==a2 && s1[2]==s2[2]){
				w+=1;
				sum--;
			}
			if(a1==a2 && s1[2]+1==s2[2]){
				w+=1;
				sum--;
			}
			if(a1==a2 && s1[2]-1==s2[2]){
				w+=1;
				sum--;
			}
		}
	}
	if(w==0){
		cout<<"0000";
		return 0;
	}
	cout<<w;
}
