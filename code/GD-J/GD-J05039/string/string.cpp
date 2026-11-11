#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long s,d[200005],f=0,g=0;
	char e[200005];
	cin>>s;
	for(long long i=0;i<s;i++){
		cin>>d[i]>>e[i];
	}
	string a;
	while(s!=0){
		for(long long i=0;i<d[f];i++){
		a[g]=e[f];
		g++;
		} 
		s--;
		f++;
	}
	long long i=0,j=g-1,b=(i+j)/2,c=0;
	while(b!=0){
		if(a[i]!=a[j]) c++;
		i++;
		j--;
		b--;
	}
	cout<<c;
	return 0;
	}
