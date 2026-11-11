#include <bits/stdc++.h>
using namespace std;
char a[10],b[10];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if (c1 == c2){
		cout<<1;
	}else{
		cout<<0;
	}
	a[1] = s1[0];
	a[2] = s1[1];
	a[3] = s1[2];
	b[1] = s2[0];
	b[2] = s2[1];
	b[3] = s2[2];
	
	
	if (c1 == c2){
		if (a[1] == b[1] && a[2] == b[2]){
			cout<<1;
		}else{
			cout <<0;
		}
	}else{
		cout<<0;
	}
	
	
	if (c1 == c2){
		if (a[1] == b[1] && a[2] == b[2]){
			if (a[3]=='D'&& b[3]=='F'|| b[3]=='D'&&a[3]=='F'){
				cout<<1;
			}else if(a[3]!='D'&&a[3]!='F'&&b[3]!='D'&&b[3]!='F'){
				cout<<1;
			}else{
				cout<<0;
			}
		}else{
			cout <<0;
		}
	}else{
		cout<<0;
	}
	
	
	
	if (c1 == c2){
		if (a[1] == b[1] && a[2] == b[2]){
			if (a[3] == 'A'&&b[3] == 'B'){
				cout<<1;
			}else if(a[3] == 'B'&&b[3] == 'C' || a[3] == 'B'&&b[3] == 'A'){
				cout<<1;
			}else if(a[3] == 'C'&&b[3] == 'B' ){
				cout<<1;
			}else if(a[3] == 'D'&&b[3] == 'F' ){
				cout<<1;
			}else if(a[3] == 'F'&&b[3] == 'D' ){
				cout<<1;
			}else{
				cout<<0;
			}
		}else{
			cout<<0;
		}
	}else{
		cout<<0;
	}
	
	
	return 0;
} 
