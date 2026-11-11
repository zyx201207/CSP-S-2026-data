#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],t1,t2,s,k1,k2,k;
char b[200005];
stack<long long> c;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n%2!=0) k=n/2+1;
	for(int i=1; i<=n; i++)
	{
		cin>>a[i]>>b[i];
	 } 
	 for(int i=1,j=n; i<n/2,j>n/2; i++,j--)
	 {
	 	
	 	if(a[i]==a[j] && b[i]!=b[j])
	 	{
	 		s+=a[i];
		}
		else if(a[i]!=a[j])
		{
			if(a[i]<a[j])
			{
				if(b[i]!=b[j])
				{
					s+=a[i];
					//cout<<"1";
				 } 
				if(i+1==k || j-1==k) t1=a[j]-a[i];
				a[j]=a[j]-a[i];
				i++;
			}
			else if(a[i]>a[j])
			{
				if(b[i]!=b[j])
				{
					s+=a[j];
				 } 
				if(i+1==k || j-1==k) t2=a[i]-a[j];
				a[i]=a[i]-a[j];
				j--;
			}
		}
	 }
	 if(n%2!=0)
	 {
	 	if(t1!=0) s+=min(t1,a[n%2]);
	 	else s+=min(t2,a[n%2]);
	 }
	 
	 cout<<s;
	 //cout<<t2;
	return 0;
}//Trick||Treat!


