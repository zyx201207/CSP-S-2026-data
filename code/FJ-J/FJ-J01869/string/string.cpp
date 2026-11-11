#include<bits/stdc++.h> 
using namespace std;
long long a[200005],b,c,d,e,n,m,s,s1,s2;
char A[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>A[i];
	}
	b=1;
	d=n;
	while(b<=d){
		if(!s)s+=a[b]; 
		if(!s1)s1+=a[d];
		s2=min(s,s1);
		if(A[b]!=A[d])m+=s2;
		s-=s2;
		s1-=s2;
		if(!s)b++;
		if(!s1)d--;
	}
	cout<<m;
	return 0;
}
