//GZ-J00647 盘州市第二中学 王玺童 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,h=0;
	cin>>n>>m;
	int arr[n];
	for(int i=0;i<n;i++)
	cin>>arr[i];
	for(int i=0;i<n-m;i++)
	{
		int temp=h;
		for(int j=i+1;j<=n;j++)
		{
			int y=0;
			int temp=h;
			h=arr[i];
			while(y<m-1)
			{
			h=h&arr[j+y];
			y++;
			}
			h=max(temp,h);
		}
	}
	cout<<h;
	return 0;
}
