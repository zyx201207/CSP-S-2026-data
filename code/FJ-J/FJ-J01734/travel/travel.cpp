#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int ans[10];
int k=0;
bool f=1,fl=1;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if ( c1==c2 )
		ans[++k]=1;
	else
	{
		cout<<"0000";
		return 0;
	}
	//求同一车厢
		
	for ( int i=0; i<2; i++ )
	{
		if ( s1[i]!=s2[i] )
			f=0;
	}
	if ( !f ) ans[++k]=0;
	else ans[++k]=1;
	//求同一排 
	
	if ( f )
	{
		if ( (s1[2]>='A' && s1[2]<='C') && (s2[2]>='A' && s2[2]<='C') )
			ans[++k]=1;
		else if ( (s1[2]>='D' && s1[2]<='F') && (s2[2]>='D' && s2[2]<='F') )
			ans[++k]=1;
		else ans[++k]=0,fl=0;
	}
	else ans[++k]=0;
	//求同一侧
	
	if ( fl==1 )
	{
		if ( (s1[2]+1==s2[2] || s1[2]+1==s1[2]) )
			ans[++k]=1;
		else 
			ans[++k]=0;
	}
	else ans[++k]=0;
	//求是否相邻  
	
	for ( int i=1; i<=k; i++ )
		cout<<ans[i];
	return 0;
}
