#include<bits/stdc++.h>
using namespace std;
int card[200010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a=1,b=0;
	int t;
	cin>>t;
	for(int i=2;i<=n;i++){
	 	int tmp;
	 	cin>>tmp;
		 if(tmp==t)a++;
		 else b++; 
	}
	cout<<a<<" "<<b;
	return 0;
}
