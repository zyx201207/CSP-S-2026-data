#include <bits/stdc++.h>
using namespace std;
long long n,z,k,minm;
char a;
struct str{
	long long l,z;
}s[200005]; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	while(n--){
		cin>>z>>a;
		k++;
		s[k].l=z;
		s[k].z=a;
	}
	long long l=1,r=k;
	while(l!=r){
		bool f=1;
		if(s[l].z==s[r].z){
			f=0;
		}
		if(s[l].l>s[r].l){
			if(f) minm+=s[r].l;
			s[l].l-=s[r].l;
			r--;
		}else{
			if(f)minm+=s[l].l;
			s[r].l-=s[l].l;
			l++;
		}
	}
	cout<<minm;
	return 0;
}
