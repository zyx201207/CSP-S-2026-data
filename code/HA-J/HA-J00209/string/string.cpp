#include<bits/stdc++.h>
using namespace std;
int h[26];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string c,m;
	int n;
	int a[200001],o,g;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c;
		int k=i;
		for(int j=1;j<=a[i];j++)
		{
			m+=c;
		}
	}
	 g=m.size();
	 if(g%2==0)
	 {
	 	for(int i=1;i<=26;i++)
		{
			h[m[i]-'0']++;		
			
		}	
	 }
	 sort(h+1,h+26);
	 g=g-h[26];
		cout<<g;

}
