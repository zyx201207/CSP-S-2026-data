#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int a[N];
int s[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<n;i++){
		s[i]=s[i]+(a[i+1]-a[i]);
	}
	s[0]=0;
	int sum=0;
	int l=0;
	int maxn=0;
	for(int i=1;i<=n;i++){
		if(sum>m){
			while(sum>m){
				sum-=s[l];
				l++;
			}
		}
		else{
			sum+=s[i];
			maxn=max(i-l,maxn);
		} 
	}
	cout<<maxn;
	return 0;
} 
