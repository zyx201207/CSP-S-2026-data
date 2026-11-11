#include<bits/stdc++.h>
using namespace std;

long long arr[500005],brr[500005];
long long m;

bool cmp(long long a,long long b){
	return a>b;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n;
	cin>>n>>m;
	int f=1;
	
	for(long long i=1;i<=n;i++){
		scanf("%lld",&arr[i]);
		if(arr[i]!=i) f=0;
	}
	//a[i]=i
	long long w=arr[2]-arr[1];
	long long f2=1;
	for(long long i=2;i<n;i++){
		if(w!=arr[i+1]-arr[i])f2=0;
	}
	if(f){
		long long h=0;
		long long i;
		f=1;
		for(i=1;i<=m;i++){
			if(m-h<i){
				cout<<i;
				f=0;
				break;
			}
			h+=i;
		}
		if(f) cout<<i+1;
		//cout<<i;
	}else if(f2){
		long long h=0;
		long long d=arr[2]-arr[1];
		int f=1;
		long long i;
		for(i=d;i<=m;i+=d){
			//cout<<i<<endl;
			if(m-h<i){
				cout<<i/d;
				f=0;
				break;
			}
			h+=i;
		}
		if(f) cout<<i/2;
	}else{
		sort(arr+1,arr+1+n);
		brr[1]=arr[1];
		for(int i=2;i<=n;i++){
			brr[i]=arr[i-1]-arr[i];
			//cout<<brr[i]<<endl;
			//cout<<brr[i]<<" ";
		}
		sort(brr+1,brr+1+n,cmp);
		for(int i=1;i<=n;i++){
			m+=brr[i];
			//cout<<brr[i]<<" ";
			//cout<<m<<" ";
			//cout<<brr[i]<<endl;
			if(m<0){
				cout<<i-2;
				break;
			}
			if(m==0){
				cout<<i;
				break;
			}
		}
	}
	return 0;
}
