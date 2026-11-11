#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N];
int cha[N];
int he[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;cin>>n;
	long long m;cin>>m;
	bool ff=0;
	for(int i=1;i<=n;++i){
		cin>>a[i];he[i]=a[i];
	}
	for(int i=2;i<=n;++i){
		he[i]+=he[i-1];
		cha[i-1]=abs(a[i]-a[i-1]);
		if(cha[i]!=cha[i-1])ff=1;
	}
	if(!ff){
		int t;long long sum=m;
		for(int i=1;i<=n;++i){
		   cha[i]=i*cha[1];	
		   if(cha[i]>sum){
				t=i;break;
			}
		   else{
			 sum-=cha[i];}
		}
	cout<<t;return 0;
	}
	if(n<=16 and m<=1000){
		long long minn=100000000000;
		int mid=(he[n]+n/2)/n;
		for(int i=1;i<=n;++i){ 
			minn=min(abs(a[i]-mid),minn);
		}
		
		
	}
}
