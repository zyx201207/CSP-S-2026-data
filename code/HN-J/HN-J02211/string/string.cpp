#include<bits/stdc++.h>
using namespace std;
struct mx{
	long long a;
	char s;
}o[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,sum=0,k=0;
	cin>>n;
	for(int i=1;i<=n;i++){
	cin>>o[i].a>>o[i].s;
	sum+=o[i].a;
	}
	int l=n/2;
	sum=n/2;
	if(n%2)l--,sum++;
		for(int i=sum+1;i<=n;i++){
			cout<<i<<" /";
			if(o[i].s!=o[l].s)k+=o[i].a;
			else if(o[i].a==o[l].a)k+=abs(o[i].a-o[l].a);
			l--;
	    }
	cout<<k;
	return 0;
}
