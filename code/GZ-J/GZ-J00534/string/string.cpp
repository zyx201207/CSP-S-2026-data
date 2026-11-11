//GZ-J00534 兴义市弘毅中学 杨凌炜
#include<bits/stdc++.h>
using namespace std;
long long n,a[200000],s=0,sum=0,q,h;
char j[200000];
string g;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>a[i]>>j[i];
		s=s+a[i];
	}
	long long  o=0;
	for(long long i=0;i<s;i++){
		for(long long z=0;z<a[i];z++){
			g[o]=j[i];
			o++;
		}
	}
	for(long long i=1;i<s/2+1;i++){
		if(s/2!=0){
			q=s/2-i;
			h=s/2+i;
		}
		else{
			q=s/2-i;
			h=s/2;
		}
		
		if(g[q]!=g[h]){
			sum++;
		}
	}
	if(n==1){
		sum=0;
	}
	cout<<sum;
	return 0;
}
