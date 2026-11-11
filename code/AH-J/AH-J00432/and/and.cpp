#include<bits/stdc++.h>
using namespace std;
long long a[200005];
long long n,m,sum=0;
void dsf(long long s,long long num,long long need){
     	if(s==0){
			sum=max(sum,num);
			return;
		}
		if(s>need){
			return;
		}
		for(int i=need;i>=1;i--){
			dsf(s-1,num&a[i],i-1);
		}
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    long long mmmm=0,g;
    cin>>a[1];
    g=a[1];
    mmmm=a[1];
    for(int i=2;i<=n;i++){
		cin>>a[i];
		g=g&a[i];
		mmmm=max(a[i],mmmm);
	}
	if(m==1){
		cout<<mmmm;
		return 0;
	}
	if(m==n){
		cout<<g;
		return 0;
	}
	dsf(m,a[1],n);
	cout<<sum;
    return 0;
}
