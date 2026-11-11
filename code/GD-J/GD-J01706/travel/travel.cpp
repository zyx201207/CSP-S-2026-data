#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int a[5],sum=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<2;i++){
		if(c1[i]==c2[i]){
			sum++;
		}
	}
	if(sum==2){
		a[1]=1;
	}
	else{
		a[1]=0;
	}
	sum=0;
	for(int i=0;i<2;i++){
		if(c1[i]==c2[i]){
			sum++;
		}
	}
	if(sum==2){
		a[2]=1;
	}
	else{
		a[2]=0;
	}
	
	char x=s1[2],y=s2[2];
	if(x=='D'||x=='F'){
		if(y=='D'||y=='F'){
			a[3]=1;
			a[4]=1;
		}
		else{
			a[3]=0;
			a[4]=0;
		}
	}
	else if(x=='A'||x=='B'||x=='C'){
		if(y=='A'||y=='B'||y=='C'){
			a[3]=1;
			if(x=='B'||y=='B'){
			    a[4]=1;
		    }
		    else{
		    	a[4]=0;
			}
		}
		else{
			a[3]=0;
			a[4]=0;
		}
	}
	for(int i=1;i<=4;i++){
		cout<<a[i];
	}
	return 0;
}
