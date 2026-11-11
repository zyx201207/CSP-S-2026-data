#include<bits/stdc++.h>
using namespace std;
long long n,m=1,l=0,s;
string a,b;
int main(){
	/*freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);*/
	cin>>n;
	for(long long i=1;i<=n;i++){
		long long x;
		cin>>x;
		char f;
		cin>>f;
		for(long long i=1;i<=x;i++){
			a[m++]=f;
		}
	}
	for(long long i=1;i<m;i++){
		b[m-i+1]=a[i];
	}
	for(long long i=1;i<=m;i++){
		if(a[i]!=b[i]){
			l=1;
		}
	}
	if(l==0){
		cout<<0;
		return 0;
	}else{
		long long o=m/2;
		for(int i=1,j=m;i<=o,j>=o;i++,j--){
			if(a[i]!=a[j]){
				s++;
			}
		}
		cout<<s;
	}
	return 0;
}

