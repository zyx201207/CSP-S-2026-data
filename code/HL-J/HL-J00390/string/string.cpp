#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int q;
	cin>>q;
	int l=0;
	int a[1000000000];
	char b[1000000000];
	for(int i=1;i<=q;i++){
		cin>>a[i]>>b[i];
		l+=a[i];
	}
	string w1,w2;
	for(int i=1;i<l/2;i++){
		w1+=b[i];
	}if(l/2==0){
		w1+=b[l/2];
		for(int i=l;i>l/2;i++){
			w2+=b[i];
		}
	}else{
		for(int i=l;i>l/2;i++){
			w2+=b[i];
		}
	}
	int z=0;
	for(int i=1;i<=l;i++){
		if(w1[i]==w2[i]) z++;
	}
	cout<<l-z;
} 
