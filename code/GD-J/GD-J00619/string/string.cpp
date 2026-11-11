#include<bits/stdc++.h> 
using namespace std;
char s[10000000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,l,c=0,q=0;
	long long si;
	char z;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>l>>z;
		for(int j=0;j<l;j++){
			s[q]=z;
			q+=1;
		}
	}
	for(long long i=0;i<((q)/2);i++){
		if(s[i]!=s[q-1-i]){
			c+=1;
		}
	}
	cout<<c;
	return 0;
}

