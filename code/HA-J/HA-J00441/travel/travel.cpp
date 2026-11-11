#include<bits/stdc++.h>
using namespace std;
int a[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		a[0]=1;
	}
	if(a[0]==0){
		for(int i=0;i<=3;i++){
			cout<<a[i];
		}
		return 0;
	}	
	if(s1[0]==s2[0]&&s2[1]==s1[1]){
		a[1]=1;
	}
	if(a[1]==0){
		for(int i=0;i<=3;i++){
			cout<<a[i];
		}
		return 0;
	}	
	int k=0;
	if(s2[2]=='D'){
		if(s1[2]=='E'){
	 		a[2]=1;
		}
	}else if(s2[2]=='E'){
		if(s1[2]=='D'){
	 		a[2]=1;
		}
	}else{
		if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
			a[2]=1;
		}
	}
	if(a[2]==1){
		k=1;
	}
	if(k==1){
		if(s1[2]=='D'||s1[2]=='E'){
			a[3]=1;
		}else{
			if(s1[2]==s2[2]+1||s1[2]==s2[2]-1){
				a[3]=1;
			}
		}
	}
	for(int i=0;i<=3;i++){
		cout<<a[i];
	}
	return 0;
}
