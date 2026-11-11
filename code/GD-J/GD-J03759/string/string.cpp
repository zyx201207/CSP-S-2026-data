#include<iostream>
using namespace std;
const int MX=2e5+5;
long long n,a[MX],ans;
string c[MX];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>c[i];
	int i=1,j=n;
	while(i<j)
	{
		if(a[i]==a[j] && c[i]!=c[j])
		{
			ans+=a[i];
			i++;
			j--;
		}
		else if(a[i]<a[j] && c[i]!=c[j])
		{
			ans+=a[i];
			a[j]-=a[i];
			i++;
		}
		else if(a[i]>a[j] && c[i]!=c[j])
		{
			ans+=a[j];
			a[i]-=a[j];
			j--;
		}
		else if(a[i]<a[j] && c[i]==c[j])
		{
			a[j]-=a[i];
			i++;
		}
		else if(a[i]>a[j] && c[i]==c[j])
		{
			a[i]-=a[j];
			j--;
		}
		else
		{
			i++;
			j--;
		}
	}
	cout<<ans;
	return 0;
} 
