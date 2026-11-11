#include <bits/stdc++.h> 
using namespace std;
string ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	long long n,sum=0,q,p,m;
	cin>>n;
	long long a[n+10];
	char c[n+10];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
        for(int j=1;j<=a[i];j++)
        {
        	ans+=c[i];
        }
	}
	q=ans.size();
	if(q%2==1)
	{
		m=q-1;
		p=m/2;
	} 
	else p=q/2;
	for(int i=0;i<p;i++)
	{
		if(ans[i]!=ans[q-i-1])
		sum++;
	}
	cout<<sum;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
