#include<iostream>
#include<cstdio>
#include<algorithm>
#include<climits>
using namespace std;
long long a[500005];
long long b[500005];
long long c[500005];
long long n,m;
long long final_ans=INT_MIN;
bool bb;
void work(int i){
	long long sum=0;
	long long ans=1;
	bool w=true;
	c[i]=0;
	for(int j=i-1;j>=1;--j){
		c[j]=b[j]+c[j+1];
		if(sum+c[j]<=m){
			++ans;
			sum+=c[j];
		}
		else {
			w=false;
			break;
		}
	}
	if(sum<=m&&w){
		bb=true;
	}
	final_ans=max(final_ans,ans);
	
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;++i){
		b[i-1]=a[i]-a[i-1];
	}
	for(int i=n-1;i>=1;--i){
		bb=false;
		work(i);
		if(bb) break;
	}
	cout<<final_ans;
	return 0;
}
