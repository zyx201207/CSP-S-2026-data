#include<bits/stdc++.h>
using namespace std;
long long c=0,d,e,g=0,add=0;
string a=" ",b=" ";
char f;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>d;
	for(long long i=0;i<d;i++){
		cin>>e;
		cin>>f;
		for(long long j=0;j<e;j++){
			a[g++]=f;
		}
	}
	for(long long i=0;i<sizeof(a);i++){
		if(a[i]!=NULL) add++;
	}
	for(long long i=0;i<add;i++){
		b[i]=a[i];
	}
	for(long long i=0;i<add/2;i++){
		swap(b[i],b[add-1]);
	}
	for(long long i=0;i<add;i++){
		if(b[i]!=a[i]) c++;
	}
	cout<<c;
	return 0;
} 
