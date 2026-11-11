#include<bits/stdc++.h>
using namespace std;
long long a[200100],ans=0;
char b[200100];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
	 } 
	 int j=n;
	 for(int i=1;i<=n;i++)
	 {
	 	if(i>=j)break;
	 	if(a[i]==a[j]&&b[i]==b[j])
		 {
		 	j--;
			 continue;
		 }
	 	if(a[i]==a[j])
	 	{
	 		ans+=a[i];
	 		j--;
	 		
		 }
		 else if(b[i]==b[j])
		 {
		 	if(a[i]-a[j]>1&&i-j>2)ans+=abs(a[i]-a[j]);
		 	j--;
		 }
		 else 
		 {
		 	if(a[i]>a[j])
		 	{
		 		ans+=a[j];
		 		a[i]-=a[j];
		 		j--;
				 i--;
			 }
			 else
			 {
			 	ans+=a[i];
		 		a[j]-=a[i];
			 }
		 }
	 }
	 cout<<ans;
	return 0;
}
