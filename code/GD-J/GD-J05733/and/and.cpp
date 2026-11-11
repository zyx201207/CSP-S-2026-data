#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int a,b,c[100005],cnt=0;
	cin>>a>>b;
	for(int i=1;i<=a;i++)
	{
		cin>>c[i];
	}
	if(b==1)
	{
		cnt=c[1];
		for(int i=2;i<=a;i++)
	{
		if(cnt<c[i])
		{
			cnt=c[i];
		}
	}
	}
	cout<<cnt;
	return 0;
}
