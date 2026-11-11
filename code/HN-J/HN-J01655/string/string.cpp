#include<bits/stdc++.h>
using namespace std;
long long n,a[200009],cnt;
char s[200009];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>s[i];
	int l=1,r=n,t=a[l];
	while(l<=r){
		if(t==0)t=a[l];
		if(s[l]!=s[r]){
			if(a[l]>=a[r]){
				if(t==a[l]){
					t-=a[r];
				    cnt+=a[r];
				}
				else cnt+=t;
			}
		}
		if(t!=0)r--;
		else{l++;r--;}
	}
	cout<<cnt;
	return 0;
}
