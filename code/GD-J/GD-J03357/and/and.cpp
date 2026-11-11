#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m;
int a[N];
long long sum;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
	}
	for(int j=30;j>=0;j--){
		int ans=0;
		for(int i=1;i<=n;i++){
			int k=(a[i]>>j)&1;
			ans+=k;
		}
		if(ans>=m){
			for(int i=1;i<=n;i++){
				int k=(a[i]>>j)&1;
				if(!k)a[i]=0;
			}
			sum+=(1<<j);
		}
//		cout<<"j="<<j<<" sum="<<sum<<"\n";
	}
	cout<<sum;
}
/*
3  -> 0011
15 -> 1111
12 -> 1100
12 -> 1100
*/
