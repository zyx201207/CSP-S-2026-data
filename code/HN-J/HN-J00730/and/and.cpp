#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int n,m,a,n_[200005],n1[200005]={-1},x,s;
int if_(int n)
{
	for(int i=1;i<=18;i++)
		if(n==pow(2,i)-1) return n;	
	return 0;
}
int main()
{
	freopen("and1.in","r",stdin);
	freopen("and1.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) 
	{
		cin>>n_[i];
		if(if_(n_[i])==n_[i]) n1[x++]=n_[i];
	}
	if(n==2 && n1[0]==-1) cout<<max(n_[0] & n_[1],max(n_[1],max(n_[2],max(n_[2],max(n_[3],max(n_[3],max(n_[4],max(n_[4],max(n_[5],max(n_[5],n_[6]))))))))));
	else if(n==2)cout<<max(n1[0] & n1[1],max(n1[1],max(n1[2],max(n1[2],max(n1[3],max(n1[3],max(n1[4],max(n1[4],max(n1[5],max(n1[5],n1[6]))))))))));
	else cout<<(n_[0] & n_[1] & n_[2])<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
