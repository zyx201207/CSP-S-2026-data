#include<bits/stdc++.h>
using namespace std;
int a[200005];
char c[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	long long n,cnt=0,ans=0,len=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		len+=a[i];
	}
	for(int i=1;cnt<len/2;i++){
		int k=a[i];
		char t=c[i];
		cnt+=k;
		while(k>0)
		{  
			if(k>=a[n]){
				if(c[n]!=t)
				 ans+=a[n];
				k-=a[n];
			}
			else{
				if(c[n]!=t)
				 ans+=k;
				a[n]-=k;
				break;
			}
			n--;
		}
	}
	cout<<ans;
	return 0;
}
