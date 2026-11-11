#include <bits/stdc++.h>
using namespace std;
long long a[200005];
string S;
char c;
long long len;
//long long len[200005],w;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c;
		len+=a[i];
		for(int j=1;j<=a[i];j++)
		S+=c;
	}
	/*long long l=1,r=len[n],lenr,lenl;
	while(l!=r)
	{
		if(c[l-1]!=c[r-1])
		{
			for(int i=1;i<=n;i++)
			{
				if(c[r-1]-len[i]>=0)
				 lenr=i+1;
			}
			for(int i=1;i<=n;i++)
			{
				if(c[l-1]-len[i]>=0)
				 lenl=i+1;
			}
			
			w+=min(a[lenl],a[lenr]);
			l=l+min(a[lenl],a[lenr]);
			r=r-min(a[lenl],a[lenr]);
		}
	}
	cout<<w;*/
	long long w=0;
	for(int i=0;i<len/2;i++)
	{
		if(S[i]!=S[len-i-1])
		w++;
	}
	cout<<w;
	return 0;
}
