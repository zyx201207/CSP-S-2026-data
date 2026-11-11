#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long d[100001]={0};
	long long L[100001]={0};
	long long n,ans=0;
	cin>>n;
	long long pos=0,pos1=0;
	long long dongle=0;
	for(long long i=0;i<n;i++){
		long long p;
		cin>>p;
		char o;
		cin>>o;
		
		d[pos]=o-'a';
		pos+=1;
		L[pos1]=p;
		pos1++;
		dongle+=p;
	}
	pos=0;
	for(long long i=0;i<dongle/2;i++){
		long long point1=0,p1;
		long long point2=n-1,p2,k1,k2;
		if(i-k1>L[point1]){
			point1++;
			k1=i;
		}
		p1=d[point1];
		if(i-k2>L[point2]){
			point2--;
			k2=i;
		}
		p2=d[point2];
		if(p1!=p2){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
