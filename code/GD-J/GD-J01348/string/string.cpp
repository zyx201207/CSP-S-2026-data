#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],l=1,r,ans,wl,wr;
char b[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	r=n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>b[i];
	wl=a[1],wr=a[n];
	while(l<r)
	{
		if(b[l]==b[r])
			if(wl>wr) wl-=wr,r--,wr=a[r];
				else if(wl<wr) wr-=wl,l++,wl=a[l];
					else l++,r--,wr=a[r],wl=a[l];
		else 
			if(wl>wr) ans+=wr,wl-=wr,r--,wr=a[r];
				else if(wl<wr) ans+=wl,wr-=wl,l++,wl=a[l];
					else ans+=wl,l++,r--,wr=a[r],wl=a[l];
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
