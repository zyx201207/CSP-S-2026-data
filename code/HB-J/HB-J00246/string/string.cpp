#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,step=1;
	cin>>n;
	string a;
	for(long long i=0;i<n;i++)
	{
		long long w;
		char a1;
		cin>>w>>a1;
		for(long long j=0;j<w;j++){
			a[step]=a1;
			step++;
		}
	}
	long long len=step;
	long long cnt=step/2;
	for(long long i=1;2*i<=len;i++)
	{
		if(a[i]==a[len-i])
			cnt--;
	}
	cout<<cnt;
	return 0;
}
//*** stack smashing detected ***:terminated
//Aborted
