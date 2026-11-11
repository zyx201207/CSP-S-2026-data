#include <bits/stdc++.h>
using namespace std;
char s,a[200050],b[100025];
long long n,x,ant=0,sum=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>s;
		for(int j=ant;j<x+ant;j++){
			a[j]=s;
		}
		ant+=x;
	}/*
	for(int j=0;j<ant;j++){
		cout<<a;
	}*/
	for(int i=0;i<ant/2;i++){
		b[i]=a[i];
	}
	if(ant%2==0){
		for(int i=ant/2,j=0;i<ant,j<ant/2;i++,j++){
			if(a[i]==b[j]){
				sum++;
			}
		}
		cout<<ant/2-sum;
	}
	else{
		for(int i=ant/2+1,j=0;i<ant,j<ant/2;i++,j++){
			if(a[i]==b[j]){
				sum++;
			}
		}
		cout<<ant/2-sum;
	}
	return 0;
}
