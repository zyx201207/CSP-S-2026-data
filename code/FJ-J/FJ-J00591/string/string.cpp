#include<bits/stdc++.h>
using namespace std;
int n,a[200005],x;
long long s,l;
char c[200005];
string cath="";
int main(){
	freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
	for(int i=1;i<=n;i++){
		l+=a[i];
		for(int j=0;j<a[i];j++){
			cath+=c[i];
		}
	}
	for(long long i=0,j=l-1;i<=l/2,j>=(l+2)/2;i++,j--){
		if(cath[i]!=cath[j])s++;
	}
	cout<<s;
	return 0;
}
