#include<bits/stdc++.h>
using namespace std;
long long a[200001];
char c[114514];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    long long n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i]>>c[i];
	}
	long long cnt=0;
	int aa=1,cc=1;
	while(1)
	{
		if(aa>=n+1-cc)
		{
			break;
		}
		if(c[aa]==c[n+1-cc])
		{
			if(a[aa]>a[n+1-cc])
			{
		        a[aa]-=a[n+1-cc];
		        a[n+1-cc]=0;
				cc++;
			}
			else if(a[aa]<a[n+1-cc])
			{
			    a[n+1-cc]-=a[aa];
				a[aa]=0;
		        
				aa++;
			}
			else
			{
				a[aa]=0;
				a[n+1-cc]=0;
				aa++;
				cc++;
			}
		}
		else
		{
			cnt+=min(a[aa],a[n+1-cc]);
			if(a[aa]>a[n+1-cc])
			{
			    
		        a[aa]-=a[n+1-cc];
		        a[n+1-cc]=0;
				cc++;
			}
			else if(a[aa]<a[n+1-cc])
			{
			    a[n+1-cc]=a[n+1-cc]-a[aa];
				a[aa]=0;
		        
				aa++;
			}
			else
			{
				a[aa]=0;
				a[n+1-cc]=0;
				aa++;
				cc++;
			}
		}
	}
	cout<<cnt;
	return 0;
}

