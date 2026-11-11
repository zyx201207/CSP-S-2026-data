#include <bits/stdc++.h>
using namespace std;
long long n,a,len,cnt;
char c,x2[20000003];
string x;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>c;
		for(int j=0;j<a;j++){
			x2[len]=c;
			len++;
		}
	}
	x=x2;
	long long r=len/2-1,l;
	if(len%2)l=r+2;	
	else l=r+1;
	while(r>=0){
		if(x[r]!=x[l]) cnt++;
		r-=1;
		l+=1;
	}
	cout<<cnt;
	return 0;
}
