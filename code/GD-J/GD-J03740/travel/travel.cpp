#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r","std.in");
	freopen("travel.out","w","std.out");
	int c1,c2=0;
	char s1[3],s2[3];
	cin>>c1;
	for(int i=0;i<3;i++){
		cin>>s1[i];
	}
	cin>>c2;
	for(int i=0;i<3;i++){
		cin>>s2[i];
	}
	int a[4]={0};
	int p=s1[1];
	int q=s2[1];
	char c=s1[2];
	char d=s2[2];
	if(c1==c2){
		a[0]=1;
	}
	else{
		cout<<"0000";
		return 0;
	}
	if(p==q){
		a[1]=1;
	}
	else{
		cout<<"1000";
		return 0;
	}
	if(c=='A'||c=='B'||c=='C'){
		if(d=='D'||d=='F'){
			a[2]=0;
		}
		else{
			a[2]=1;
		}
	}
	else if(c=='E'||c=='F'){
		if(d=='A'||d=='B'||d=='C'){
			a[2]=0;
		}
		else{
			a[2]=1;
		}
	}
	if(c=='B'&&a[2]==1){
		a[3]=1;
	}
	if(c=='A'||c=='C'&&d=='B'&&a[2]==1){
		a[3]=1;
	}
	if(c=='E'||c=='F'&&a[2]==1){
		if(d=='E'||d=='F'){
			a[3]=1;
		}
	}
	for(int i=0;i<4;i++){
		cout<<a[i];
	}
	return 0;
}
