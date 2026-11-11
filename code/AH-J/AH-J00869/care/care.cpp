#include<bits/stdc++.h>
using namespace std;
int a[10050],b[10050];
bool h(int a)
{
	for(int i=0;i<a;i++)
	if(b[i]==a)
	return 0;
	return 1;
}
int main()
{
freopen("care.in","r",stdin);
freopen("care.out","w",stdout);
int n,m;
cin>>n>>m;
for(int i=0;i<n;i++)
cin>>a[i];
for(int i=0;i<n;i++)
{
	int k=0;
	b[10050]={0};
	for(int j=i;j<n;j++)
	{
		if(h(a[j]))
		b[k++]=a[j];
	}
}
fclose(stdin);
fclose(stdout);
return 0;
}

