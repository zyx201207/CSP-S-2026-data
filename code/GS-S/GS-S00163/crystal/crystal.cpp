#include<bits/stdc++.h>

using namespace std;
long long n,m,sj[500005],c[200005],x[200005], k=0;
long long best=0;
int main()
{
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	ios::sync_with_stdio;
	cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++)	cin>>sj[i];
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
				if(sj[i] > sj[j]){
					c[i]+=abs(sj[i]-sj[j]);	
					x[i]++;	
				}
				else if(sj[i] == sj[j]){
					x[i]++;						
					}
					
			}		
	}
	for(int i=0;i<n;i++){
		if(c[i]>m)
		{
			x[i]=0;
		}
	}
	for(int i=0;i<n;i++)
	{
		if(x[i]>best)
		{
			best=x[i];
		}
	}
	cout << best;
	return 0;
} 

