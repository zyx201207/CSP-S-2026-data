#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int cnt;
	for(int i=0;i<n;i++)
	{
		cnt=0;
		for(int j=0;j<n;j++)
		{
			if(a[j]>a[i])
			{
			    cnt++; 
		    }
		}
		if(cnt==m-1){
			cout<<a[i]<<endl;
			break;
		}
	}
	return 0;
}
