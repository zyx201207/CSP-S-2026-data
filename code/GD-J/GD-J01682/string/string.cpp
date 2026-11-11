#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],b[200005],ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		char c;
		cin>>a[i]>>c;
		b[i]=c-'a'+1;
	}
	long long l=1,r=n;
	long long x=a[1],y=a[r];
	while(l<=r)
	{
		if(b[l]==b[r])
		{
			if(x>y)x-=y,r--,y=a[r];
			else if(x<y)y-=x,l++,x=a[l];
			else if(x==y)l++,r--,x=a[l],y=a[r];
		}
		else{
			if(x>y)ans+=y,x-=y,r--,y=a[r];
			else if(x<y)ans+=x,y-=x,l++,x=a[l];
			else if(x==y)ans+=x,l++,r--,x=a[l],y=a[r];
		}
	}
	cout<<ans;
	return 0;
}
