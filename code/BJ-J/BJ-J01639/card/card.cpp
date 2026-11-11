#include<bits/stdc++.h>
using namespace std;
int a[500005];
int h[500005];
queue <int> q;
queue <int> q1;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	cout<<n-1<<" "<<n-m<<" "<<(n-2)*2;
	//~ for(int i=1;i<=m;i++)
	//~ {
		//~ for(int j=i;j<=n;j++)
		//~ {
			//~ q.push(a[i]);
			//~ q1.push(a[i]);
			//~ else{
				//~ while(q.front()!=a[i])
				//~ {
					//~ q.pop();
					//~ q1.pop();
				//~ }
				//~ q.pop();
				//~ q1.pop();
				//~ q.push(a[i]);
				//~ q1.push(a[i]);
			//~ }
			//~ if(q.size()==1)
			//~ {
				//~ h[i]++;
				//~ continue;
			//~ }
		//~ }
		//~ cout<<h[i]<<" ";
	//~ 
	
	return 0;
}
