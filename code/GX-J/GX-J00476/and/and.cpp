#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],t,maxx,z;
string s,r,g;
long long awy(string a,string b,long long l){
	string q;
	for(int i=0;i<l;i++){
		if(a[i]==b[i] && a[i]=='1') q[i]==1;
		else q[i]==0;
	}
	long long w=0;
	for(int i=0;i<q.size();i++) w+=q[i]*(2^i);
	return w; 
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		r=s;
		cin>>a[i];
		t=a[i];
		long long l=0;
		while(t!=0){
		s[l]=t%2;
		t/=2;
		z++;
		}
		maxx=max(maxx,awy(s,r,z));
	}	
	cout<<maxx;
	return 0;
}
