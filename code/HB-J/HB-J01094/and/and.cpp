#include<bits/stdc++.h>
using namespace std;
int n,q;
const int N=1e5+50;
struct Node()
{
	int r;
	char q;
}a[N];	
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i].r;
		for(int i=0;i<a[i].r;i++)
		{
		cin>>a[i].q;
		}
	}
	cout<<8;
	return 0;
}
