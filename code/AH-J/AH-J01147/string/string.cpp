#include<bits/stdc++.h>
using namespace std;
char b[200050],s[200050];
long long n,a[200050],i,j,k=1,m=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	
	for(i=1;i<=n;i++){
		for(j=1;j<=a[i];j++){
			s[k]=b[i];k++;
		}
	}
	k--;
	for(i=1,j=k;i<j;i++,j--){
		if(s[i]!=s[j]){
			m++;
		}
	}
	cout<<m;
	return 0;
}
