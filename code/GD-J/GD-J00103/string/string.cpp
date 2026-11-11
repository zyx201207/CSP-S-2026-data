#include<bits/stdc++.h>
using namespace std;
int n,a[200005],s,bs;
char c[200005];
string b,l,r;
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++){
			b+=c[i];
		}
		s+=a[i];
		s=s%2;
	}
	bs=b.size();
	if(s){
		for(int i=0;i<(bs-1)/2;i++){
			l+=b[i];
		}
		for(int i=(bs+1)/2;i<bs;i++){
			r+=b[i];
		}
		s=0;
		for(int i=0;i<bs/2;i++){
			if(l[i]!=r[i]){
				s++;
			}
		}
	}else{
		for(int i=0;i<bs/2;i++){
			l+=b[i];
		}
		for(int i=bs/2;i<bs;i++){
			r+=b[i];
		}
		for(int i=0;i<bs/2;i++){
			if(l[i]!=r[i]){
				s++;
			}
		}
	}
	cout<<s;
}
