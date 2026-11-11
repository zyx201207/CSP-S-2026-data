#include<bits/stdc++.h>
using namespace std;
long long num[200004];
char zm[200004];
long long a,s,ls=0,sum=0,k=0,yx=0;
void clb(int i){
	ls=num[i];
	yx=ls;
	k=1;
	while(num[a-k-i]<ls){
		if(zm[a-k-i]==zm[i]) yx-=num[a-k-i];
		ls-=num[a-k-i];
		num[a-k-i]=0; 
		k++;
	}
	if(zm[a-k-i]==zm[i]) yx-=ls;
	num[a-k-i]-=ls;
	sum+=yx;
	return;
}
void cls(int i){
	ls=num[a-1-i];
	yx=ls;
	k=0;
	while(num[k+i]<ls){
		if(zm[k+i]==zm[a-1-i]) yx-=num[k+i];
		ls-=num[k+i];
		num[k+i]=0; 
		k++;
	}
	if(zm[k+i]==zm[a-1-i]) yx-=ls;
	num[k+i]-=ls;
	sum+=yx;
	return;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>a;
	for(int i=0;i<a;i++) cin>>num[i]>>zm[i];
	for(int i=0;i<a/2;i++){
		if(num[i]==num[a-1-i]){
			if(zm[i]==zm[a-1-i]) continue;
			else sum+=num[i];
		} 
		else if(num[i]>num[a-1-i])
			clb(i);
		
		else
			cls(i);
	}
	cout<<sum;
	return 0;
} 
