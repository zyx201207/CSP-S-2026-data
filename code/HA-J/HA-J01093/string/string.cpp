#include<bits/stdc++.h>
using namespace std;
long long a[200086];
char b[200086];
long long len=0;

int ccn(long long n)
{
	long long cs=0,ci=0;
	while(cs<n) {
		cs+=a[ci];
		ci++;           
	}
	return ci-1;
}

int ccs(long long n)
{
	long long cs=0,ci=0;
	while(cs<n) {
		cs+=a[ci];
		ci++;           
	}
	return cs;
}

int findn(long long beg,long long end,char ca)
{
	long long bb=ccn(beg),ee=ccn(end);
	long long sn=0;
	if(bb==ee){
		if(b[bb]==ca) return 0;
		else return end-beg;
	}
	else{
		if(b[bb]!=ca) sn+=ccs(beg)-beg;
		if(b[ee]!=ca) sn+=a[ee]-(ccs(end)-end);
	}
	
	for(long long i=bb+1;i<ee;i++)
	{
		if(b[i]!=ca) sn+=a[i];
	}
	return sn;
}

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n;
	cin>>n;
	
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>b[i];
		len+=a[i];
	}
	long long sl=0,sr=0,p=0,q=n-1,cccn=0;

	while(true)
	{
		cccn+=a[p];
		if(cccn>len/2){
			sl+=findn(len/2,len-(cccn-a[p]),b[p]);
			break;
		}
		sl+=findn(len-cccn,len-(cccn-a[p]),b[p]);
		p++;
	}
	cccn = 0;
	while(true)
	{
		cccn+=a[q];
		if(cccn>len/2){
			sr+=findn(cccn-a[q],len/2,b[q]);
			break;
		}
		sr+=findn(cccn-a[q],cccn,b[q]);
		q--;
	}
	cout<<min(sl,sr);
	
	fclose(stdin);
	fclose(stdout);
}
