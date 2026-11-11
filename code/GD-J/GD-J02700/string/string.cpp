#include<bits/stdc++.h>
using namespace std;

const int N=2*1e5+5;

struct ku{
	long long sum;
	char num;
}a[N];


int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	for(int i=1;i<=n;i++){
		long long o;
		char t;
		cin>>o>>t;
		a[i].sum+=o,a[i].num=t;
	}
	long long ans=0;
	long long j=n,i=1;
	while(i<j){
		if(a[i].num!=a[j].num){
			ans+=min(a[i].sum,a[j].sum);
		}
		long long mn=min(a[i].sum,a[j].sum);
		a[i].sum-=mn;
		a[j].sum-=mn;
		if(a[i].sum==0)i++;
		if(a[j].sum==0)j--;
		
	}
	cout<<ans;
	return 0;
} 
