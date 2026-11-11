#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a[200002]={0},k=0,f,l,r,ld,rd,x=0;
	char b[200002];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>f>>b[i];
		k=k+f;
		a[i]=k;
	}
	l=1;
	ld=1;
	r=k;
	rd=n;
	for(int i=1;i<=k/2;i++){
		if(b[ld]!=b[rd]) x++;
		l++;
		r--;
		if(l>a[ld]) ld++;
		if(r==a[rd-1]) rd--;
	}
	cout<<x;
	return 0;
}
