#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.ans","w",stdout);
	vector <long long>a;
	unsigned long long m,n;
	int p,q,maxn=1,c,s,cnt=0;
	cin>>n>>m;
	int sumd[n-1][n-1]={};
	int delt[n-1];
	memset(delt,-1,sizeof(delt));
	for(int i=0;i<n;++i)
	{
		cin>>s;
		a.push_back(s);
		if(i>0)delt[i-1]=a[i]-a[i-1];
	}	
	for(p=0;p<n;++p)
	{
		for(q=p;q<n;++q)
		{	
			for(int e=p;e<q;++e)
			{
				for(int f=e;f<q;++f)
				{
					sumd[p][q]+=delt[f];
				}
			}
			cout<<"";
			if(p==q)sumd[p][q]=0;
			if(sumd[p][q]>m)sumd[p][q]=0;
			if((maxn<(q-p+1))&&(sumd[p][q]!=0))maxn=q-p+1;
		}
	}
	cout<<maxn;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
