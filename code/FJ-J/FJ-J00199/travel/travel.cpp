#include<bits/stdc++.h> 
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	
	int a=int(s1[0]),b=int(s2[0]),c=int(s1[1]),d=int(s2[1]);
	int A=max(int(s1[2]),int(s2[2])),B=min(int(s1[2]),int(s2[2]));
	int C=int(c1[0])+int(c1[1]),D=int(c2[0])+int(c2[1]);
	
	if(C==D) cout<<1;
	else cout<<0;
	
	if(C==D&&a==b&&c==d) cout<<1;
	else cout<<0;
	
	if(C==D&&a==b&&c==d){
		if(A<=67) cout<<1;
		else if(B>=68) cout<<1;
		else cout<<0;
	}
	else cout<<0;
	
	if(C==D&&a==b&&c==d){
		if(A<=67){
			if(A-B==1) cout<<1;
			else cout<<0;
		}
		else{
			if(A-B==2) cout<<1;
			else cout<<0;
		}
	}
	else cout<<0;
	return 0;
}
