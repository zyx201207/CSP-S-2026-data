#include iostream <bits/stdc++.h>
using namespace std
int main(){
	freopen("string.in",'w',stdin);
	freopen("string.out",'r',stdout);
	int ai,ci,s;
	string a=[];
	cin>>ai;
	for(int=1,i<=ai,i++){
		cin>>ci;
		cin>>s;
		for(j=1,j<=ci,j++){
			a+=s;
		}
	}
	string b=[];
	for(int i=0;i<a.length(),i++){
		b[i]=a[a.length()-i];
	}
	if(a==b){
		cout<<0;
	}
	else(){
		int num=0;
		for(int i=0,i<a.length(),i++){
			if(a[i]!=a[a.length()-i]){
				a[a.length()-i]=a[i];
				num++;
			}
		}
		cout<<num;
	}
	return 0;
}
