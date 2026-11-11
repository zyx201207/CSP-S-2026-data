#include<bits/stdc++.h>
using namespace std;
long long n,a,j,d,m,z;
char c;
string b,x;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>a>>c;
		for(j=d;j<d+a;j++){
			b[j]=c;
		}
		m+=a;
		d=j;
	}
	for(long long i=0;i<m;i++){
		x[i]=b[m-i-1];
	}
	for(long long i=0;i<m/2;i++){
		if(x[i]!=b[i]){
			z++;
		}
	}
	cout<<z;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
