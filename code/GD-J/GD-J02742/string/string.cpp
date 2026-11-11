#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[200005];
char s[200005];
long long ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i]>>s[i];//³¤¶È  ·ûºÅ 
	}
	long long l=1;
	long long l1=1;
	long long r=n;
	long long r1=a[r];
	while(l<r){
		if(s[l]!=s[r]){
			long long c1=a[l]-l1+1;
			long long c2=r1;
			if(c1>c2){
				ans+=c2;
				l1+=c2;
				r--;
				r1=a[r];
			}
			else if(c1<c2){
				ans+=c1;
				l1=1;
				r1-=c1;
				l++; 
			}
			else{
				ans+=c2;
				l++;
				r--;
				l1=1;
				r1=a[r];
			}
		} 
		else{
			long long c1=a[l]-l1+1;
			long long c2=r1;
			if(c1>c2){
				r--;
				r1=a[r];
			}
			else if(c1<c2){
				l++;
				l1=1;
			}
			else
			{
				l++;
				r--;
				l1=1;
				r1=a[r];
			}
		}
	}
	cout<<ans;
	return 0;
}


