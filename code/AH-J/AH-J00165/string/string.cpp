#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","r",stdout);
	int a,b,c,d=0,e=0;
	char l[10000000000000000];
	char l1[10000000000000000];
	cin>>a;
	for(int i=0;i<a;i++){
		cin>>b>>c;
		for(int j=0;j<b;j++){
			l[d+j]=c;
		}
		d+=b;
    }
	for(int i=0;i<d/2;i++){
		l1[i]=l[d-i];
	}
	for(int i=0;i<d/2;i++){
		if(l[i]!=l1[i]){
			e++;
		}
	}
	cout<<e;
	return 0;
} 
