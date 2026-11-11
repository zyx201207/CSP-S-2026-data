#include<iostream>
#include<cstring>
using namespace std;
const int N=2e6+10;
long long  w[N];
int dist[N];
int main()
{
	freopen("migrate1.in","r",stdin);
	int c,t;
	cin>>c>>t;
	int n;long long d;
	cin>>n>>d;
	for(int i=0;i<n;i++)
		scanf("%lld",&w[i]);
	long long yuan=w[0]+d;
	int bushu=1;
	 for(int i=1;i<n;i++)
	 {
	 	if(w[i]>yuan)
	 	{
	 		bushu++;
	 		yuan+=d;
		 }
	 	dist[i]=bushu;
	 }
	for(int i=0;i<n;i++)cout<<dist[i]<<" ";
}
