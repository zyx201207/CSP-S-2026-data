#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005],s;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;m++;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
	for(int i=2;i<=n;i++)
	{
		if(c[i]==c[i-1])a[m]+=a[i];
		else a[++m]=a[i],c[m]=c[i];
	}
	for(int l=1,r=m;l<r;)
	{
		if(a[l]<a[r]){
			if(c[l]!=c[r])s+=a[l];
			a[r]-=a[l],l++;
		}
		else if(a[l]>a[r]){
			if(c[l]!=c[r])s+=a[r];
			a[l]-=a[r];r--;
		}
		else {
			if(c[l]!=c[r])s+=a[l];
			l++,r--;
		}
	}
	cout<<s;
	return 0;
}
