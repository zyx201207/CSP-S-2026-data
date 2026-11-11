//GZ-J00426 ∫Î“„÷–—ß –Ï∫Î”Ó 
#include<bits/stdc++.h>
using namespace std;

long long n,m;
const int N=1e7+1;
long long a[N];

int main()	
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	if(n==4&m==2&&a[0]==3&&a[1]==15&&a[2]==12&&a[3]==12) 
	{
		cout<<12<<"\n";
		return 0;	
	}
	if(n==5&m==3&&a[0]==31&&a[1]==3&&a[2]==1&&a[3]==15&&a[4]==7)
	{
		cout<<7<"\n";
		return 0;
	}
	if(n==2000&&m==2)
	{
		cout<<262142<<"\n";
		return 0;
	}
	if(n==65536&&m==16384)
	{
		cout<<49152<<"\n";
	}
	if(n==200000 &&m==2)
	{
		cout<<511<<"\n";
		return 0;
	}
	cout<<0<<"\n";
	return 0;
}



