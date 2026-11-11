#include<bits/stdc++.h>
using namespace std;
#define intl long long
intl n,c,v;
intl a[10001],b1[10001];
char ss[10001]; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>ss[i];
		v+=a[i];
		if(ss[i]!=ss[1]) c+=a[i];
	}
	int j=n;
	bool f=1;
	for(int i=1;i<=n;){
		if(ss[i++]!=ss[j--]){
			f=0;
			break;
		}
	}
	if(f){
		int aa=0;
		cout<<aa;
		return 0;
	}
	j=n-1;
	for(int i=2;i<=n-1;){
			if(ss[i++]==ss[j--]){
			c-=2;
		}
	}
	if(v%2==1) c--;
	cout<<c;
	return 0;
} 

