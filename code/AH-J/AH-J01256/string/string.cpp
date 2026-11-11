#include<bits/stdc++.h>
using namespace std;
long long int a[200010];
char c[200010];
int n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	int t=1,s=n,j=0;
	while(t!=s)
	{
		if(c[t]!=c[s])
		{
			if(a[t]<a[s])
			{
				j+=a[t];
				a[s]-=a[t];
				t++;
			}else if(a[t]>a[s]){
				j+=a[s];
				a[t]-=a[s];
				s--;
			}else{
				j+=a[s];
				t++;s--;
			}
		}else{
			if(a[t]<a[s])
			{
				a[s]-=a[t];
				t++;
			}else if(a[t]>a[s]){
				a[t]-=a[s];
				t++;
			}
		}
	}
	cout<<j;
	return 0;
	
}
