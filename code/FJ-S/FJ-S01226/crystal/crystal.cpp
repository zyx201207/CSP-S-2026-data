#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500007];
bool cmp(long long a,long long b){
	return a>b;
}
long long md,ii,sum,maxx=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++){
		md=m;
		ii=i+1;
		sum=1;
		while(md>=0&&ii<=n){
			md-=a[i]-a[ii];
			if(md>=0){
				sum++;
			}
			//cout<<md<<" ";
			ii++;
			
		}
		//cout<<sum<<endl;
		maxx=max(maxx,sum);
	}
	cout<<maxx;
	return 0;
}
