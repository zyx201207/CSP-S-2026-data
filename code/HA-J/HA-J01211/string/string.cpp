#include<bits/stdc++.h>
using namespace std;
long long n,a[200016],l,r,s;
char c[200016];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
	l=1;r=n;
	while(l<r){
		s+=min(a[l],a[r])*(c[l]!=c[r]);
		if(a[l]==a[r])l++,r--;
		else if(a[l]>a[r])a[l]-=a[r],r--;
		else if(a[l]<a[r])a[r]-=a[l],l++;
	}cout<<s;
	return 0;
}
