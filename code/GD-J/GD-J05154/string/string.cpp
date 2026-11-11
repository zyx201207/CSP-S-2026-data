#include<bits/stdc++.h>
using namespace std;
long long n,a[10005],sum,m,cc=0,f=0;
char b[10005];
string c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		if(f==0){
			for(int j=1;j<=a[i];j++)
			{
				c+=b[i];
			}
		}
		sum+=a[i];
		if(sum>99999999)
		{
			f=1;
		}
	}
	if(f==1){
		cout<<sum/2;
		return 0;
	}
	if(sum>0) m=(sum-1)/2;
	for(int i=0,j=c.size()-1;i<=j;i++,j--){
		if(c[i]!=c[j]){
			cc++;
		}
	}
	if(m>cc) m=cc;
	cout<<m;
	return 0;
}
