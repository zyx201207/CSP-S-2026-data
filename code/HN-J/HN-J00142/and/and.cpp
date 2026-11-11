#include<bits/stdc++.h>
using namespace std;
long long n,m,b,mx1,mx2,mx3;
struct nur{
	long long a;
	long long num;
	int bi;
}nn[200005];
bool cmp(nur x,nur y){
	if(x.num!=y.num)
	return x.num>y.num;
	else
	return x.bi>y.bi;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;	
	for(int i=0;i<n;i++){
		cin>>nn[i].a;
	}
	for(int i=0;i<n;i++){
		long long y=nn[i].a,cnt=0,sum=0; 
		while(y!=0){
			if(y%2==1)
			cnt++;
			y/=2;
			sum++;
		}
		nn[i].num=cnt;
		nn[i].bi=sum;
	}
	sort(nn,nn+n,cmp);
	long long sum=LONG_MAX;
	for(int i=0;i<m;i++){
		sum=sum&nn[i].a;
	}
	cout<<sum;
	return 0;
}
