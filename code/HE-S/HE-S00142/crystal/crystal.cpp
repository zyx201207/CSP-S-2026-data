#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500000];
int b[500000];
void pd(int x,int last){
	int sum=0;
	int ans=m;
	for(int i=0;i<n;i++){
		if(a[i]<=x){
			if(a[i]==x){
				sum++;
			}
			else if(ans>=x-a[i]){
				ans-=x-a[i];
				sum++;
			}
		}
	}
	b[x]=sum;
	return ;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long long mx=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	for(long long i=1;i<=mx;i++){
		pd(i,i-1);
	}
	int sum=0;
	for(int i=0;i<n;i++){
		sum=max(sum,b[i]); 
	}
	cout<<sum;
	return 0;
} 
