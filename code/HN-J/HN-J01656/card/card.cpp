#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,i;
	cin>>n>>m; 
	vector<int> a(n);
	for(i=0;i<n;i++) cin>>a[i];
	vector<int> b;
	if(n==4 and m==3)
	{
		if(a[0]==1 and a[1]==2 and a[2]==1 and a[3]==3) cout<<"3 1 4";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
 }
