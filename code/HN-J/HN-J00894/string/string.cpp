#include<bits/stdc++.h>
using namespace std;
int a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,b=0,sum=0,maxx=0,sy=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		sy++; 
		cin>>a[i]>>c[i];
		if(c[i]!=c[i-1]&&i>=2) b=1;
		sum+=a[i];
		if(a[i]>=maxx) maxx=a[i];
		if(c[i]==c[i-1])sy-=1; 
	}
	if(b==0||n==1) cout<<0;
	else
    {
    	if(maxx==1)
    	{
    	cout<<sy-1;
		}
	else{
			if(a[1]>=a[n])
			cout<<a[n];
			else cout<<a[1];
			}
	}
	return 0;
} 

