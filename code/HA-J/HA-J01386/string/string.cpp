#include<bits/stdc++.h>
using namespace std;
char aa[1000000005];
int main(){
	// b
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long h=1;
	cin>>n;
	for(int i=1;i<=n;i++){   
		long long a;
		char b;
		cin>>a>>b;
		for(long long j=1;j<=a;j++){   
			aa[h]=b;
			h++;
		}
	}
	h--;
	long long o=0,k=1,p=h;
	for(long long i=1;i<=h/2;i++){
		if(aa[k]!=aa[p]){
			o++; 
		}
		k++;
		p--;
	} 
	cout<<o;
	return 0;
}

