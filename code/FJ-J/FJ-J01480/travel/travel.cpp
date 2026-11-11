#include<bits/stdc++.h>
using namespace std;
int a[10];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	int j,k;
	cin>>c1>>s1>>c2>>s2;
	a[0]='A';
	a[1]='B';
	a[2]='C';
	a[3]='0';
	a[4]='D';
	a[5]='F';
	if(c1==c2){
		cout<<1;
		for(int i=0;i<2;i++){
			if(s1[i]==s2[i]){
				continue;
			}
			else{
				cout<<0<<0<<0;
				return 0;
			}
		}
		cout<<1;
		for(int i=0;i<6;i++){
			if(a[i]==s1[2]){
				j=i;
			}
			if(a[i]==s2[2]){
				k=i;
			}
	    }
		if(j<3 and k<3){
			cout<<1;
			if(j-k==1 or k-j==1){
				cout<<1;
				return 0;
			}
			else{
				cout<<0;
				return 0;
			}
		}
		else if(j>3 and k>3){
			cout<<1;
			if(j-k==1 or k-j==1){
				cout<<1;
				return 0;
			}
			else{
				cout<<0;
				return 0;
			}
		}
		else{
			cout<<0<<0;
			return 0;
		} 
	}
	else{
		cout<<0<<0<<0<<0;
	}
	return 0;
} 
