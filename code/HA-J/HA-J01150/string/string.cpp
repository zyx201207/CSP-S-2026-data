#include<bits/stdc++.h>
using namespace std;
int n;
string s;
int a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin>>n;
    int k=1;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i]>>c[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=a[i];j++)
		{
			s[k++]=c[i];
		}
	}
	k--;
	int sum=0;
	for(int i=1;i<=k/2;i++)
	{
		if(s[i]!=s[k-i+1]) sum++;
	}
	cout<<sum;
	return 0;
	//ÌÖÑá³¬Ê±£¡£¡£¡ 
} 
