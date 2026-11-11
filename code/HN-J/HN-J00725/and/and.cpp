#include<bits/stdc++.h> 
using namespace std;
int a[200005];
int s;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i]; 
	}
	sort(a,a+n);
	s=a[n-1];
	cout<<0<<" "<<a[n-1]<<" "<<s<<endl; 
	for(int i=1;i<m;i++)
	{
		cout<<i<<" "<<a[n-i-1]<<" "<<s<<endl; 
		if(s+1!=a[n-i-1]&&s-1!=a[n-i-1]){
		s=s&a[n-i-1];
		}
		else
		m++;
	}
	cout<<s;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
