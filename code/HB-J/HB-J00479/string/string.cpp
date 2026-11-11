#include <bits/stdc++.h>
using namespace std;
struct P{
	long long m;
	string s;
}a[200009];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,cnt=0,l=1,r;
	cin>>n;
	r=n;
	for(int i=1;i<=n;i++){
		cin>>a[i].m>>a[i].s;
	}
	while(l<r){
		long long k=min(a[l].m,a[r].m);
		if(a[l].s!=a[r].s) cnt+=k;
		a[l].m-=k;
		a[r].m-=k;
		if(a[l].m==0) l++;
		if(a[r].m==0) r--;
		
	}
	cout<<cnt;
}
