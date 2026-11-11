#include <bits/stdc++.h>
using namespace std;
char a[100100],b[100100],d[100100];
long long c[100100];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,lt=1,f=0,len=1,y=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		long long m;
		char s;
		cin>>m>>s;
		c[i]=m;
		d[i]=s;
		for(int j=1;j<=m;j++){
			a[len]=s;
			lt++;
			len++;

		}
	}
	if(len%2==1)f=1;
	for(int i=1;i<=len;i++){
		b[i]=a[lt];
		lt--;
	}lt=1;
	long long mi=0,rt=len,mi1=0;
	for(int i=1;i<=len;i++){
		if(d[lt]!=d[rt])y=1;
	}
	if(f){
		rt=len/2+2;
		lt=len/2;
	}
	else{
		rt=len/2+1;
		lt=len/2;
	}
	for(int i=1;i<=lt;i++){
		if(a[i]!=b[i])mi++;
	}
	for(int i=rt;i<=len;i++){
		if(a[i]!=b[i])mi1++;
	}if(y==0)cout<<"0";
	else cout<<min(mi,mi1)<<endl;

	return 0;
}
	
