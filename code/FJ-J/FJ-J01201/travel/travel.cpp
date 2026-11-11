#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
bool f=1;
char a1,a2;
long long l1,l2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	for(long long i=0;i<max(c1.size(),c2.size());i++){
		if(c1[i]!=c2[i]){
			f=0;
			break;
		}
	}
	cout<<f;
	for(long long i=0;i<2;i++){
		if(s1[i]!=s2[i]){
			f=0;
			break;
		}
	}
	cout<<f;
	a1=s1[2];a2=s2[2];
	if(a1=='A'&&a2=='D')f=0;
	if(a1=='A'&&a2=='F')f=0;
	if(a1=='B'&&a2=='D')f=0;
	if(a1=='B'&&a2=='F')f=0;
	if(a1=='C'&&a2=='D')f=0;
	if(a1=='C'&&a2=='F')f=0;
	if(a1=='D'&&a2=='A')f=0;
	if(a1=='D'&&a2=='B')f=0;
	if(a1=='D'&&a2=='C')f=0;
	if(a1=='F'&&a2=='B')f=0;
	if(a1=='F'&&a2=='C')f=0;
	if(a1=='F'&&a1=='A')f=0;
	cout<<f;
	if((a1=='C'&&a2=='D')||(a1=='D'&&a2=='C')){
		f=0;
	}else{
		l1=a1-'A';
		l2=a2-'A';
		if(llabs(l1-l2)!=1)f=0;
	}
	cout<<f;
	return 0;
}