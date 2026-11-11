#include<bits/stdc++.h> 
using namespace std;
int a[500005];
int s[300005];
//int b[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		s[a[i]]+= (i+1);
	}
	for(int i=0;i<n;i++)
	{
		s[i]+=2;
	}
	for(int i=1;i<=m;i++)
	//cout<<s[i]<<" ";
	//cout<<endl;
	for(int i=0;i<n;i++)
	for(int j=i+1;j<n;j++)
	{
		if(a[i]==a[j]){
		//cout<<l1<<"~"<<j<<endl;
		for(int l=i;l<j;l++) {
		//cout<<l<<"w "<<a[l]<<":"<<s[a[l]]<<" -"<<1<<endl;
		s[a[l]]-=(i+1);
		}
		break;
	}
		
	}
	for(int i=1;i<=m;i++)
	cout<<s[i]<<" ";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
