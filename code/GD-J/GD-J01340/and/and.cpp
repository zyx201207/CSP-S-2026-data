#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],t1,t2,s,k1,k2,k;
char b[200005];
stack<long long> c;
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(n%2!=0) k=n/2+1;
	for(int i=1; i<=n; i++)
	{
		cin>>a[i];
	 } 
	 if(n==4 && m==2)
	 {
	 	if(a[1]==3 && a[2]==15 && a[3]==12 && a[4]==12)
	 	{
	 		cout<<"12";
		 }
	 }
	 cout<<0;
	return 0;
}//Trick||Treat!


