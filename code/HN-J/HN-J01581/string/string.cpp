#include<bits/stdc++.h>
using namespace std;
long long a[200010],n,k;
char s[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>s[i];
	}
	int l=1,r=n;
	while(l<r){
		if(s[l]!=s[r]) k+=min(a[l],a[r]);
		if(a[l]>a[r]){
			a[l]-=a[r];
			r--;
		}else {
			a[r]-=a[l];
			l++;
		}
	}
	cout<<k;
	return 0;
}
