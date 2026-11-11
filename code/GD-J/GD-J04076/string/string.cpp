#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n=0,z=0,g=0;
	cin >>n;
	string q;
	for(int i=1;i<=n;i++){
		int a=0;
		char s;
		cin >>a >>s;
		while(a--){
			q[z]=s;
			z++;
		}
	}
	string l,r;
	int c=(z-1)/2;

	for(int i=0;i<=c;i++){
		l[i]=q[i];
		r[i]=q[i+c+1];
		cout <<l[i] <<r[i] <<endl;
	}
	for(int i=0;i<=c-1;i++){
		if(l[i]!=r[c-i-1]){
			g++;
		}
	}
	cout <<g;
	return 0;
} 
