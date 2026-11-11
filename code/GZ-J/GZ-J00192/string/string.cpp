//GZ-J00192ÕÅ½ÜÈð 
#include<bits/stdc++.h>
using namespace std;
int n,a[200886];long long len,l,r,ans;char c[200886];
int main(){
	freopen("string.in","r",stdin);freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i],len+=a[i];
	l=1,r=len;
	for(int i=1,j=n;l<r&&i<j;){
		bool k=c[i]!=c[j];
		if(a[i]>a[j])
			l+=a[j],r-=a[j],a[i]-=a[j],ans+=a[j]*k,j--;
		else if(a[i]<a[j])
			l+=a[i],r-=a[i],a[j]-=a[i],ans+=a[i]*k,i++;
		else l+=a[i],r-=a[i],ans+=a[i]*k,i++,j--;
	}cout<<ans;
	return 0;
}
