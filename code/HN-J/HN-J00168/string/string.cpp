#include<bits/stdc++.h>
using namespace std;
int n;
long long a[100000001];
char h[10000001];
unsigned long long s=0,l=1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		char z;
		cin>>a[i]>>z;
		for(int j=l;j<=l+a[i];j++){
			h[j]=z;
		}
		l+=a[i];
	}
	int k=l-1;
	for(int i=1;i<l;i++){
		if(h[i]!=h[k]){
			s+=1;
		}
		k--;
	}
	cout<<s/2;
	return 0;
}

