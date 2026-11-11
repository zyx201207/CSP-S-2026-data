#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	long long maxn=0;
	for(int left=0,right=1;right<n;right++){
		int nowlong=0;
		for(int i=left;i<right;i++){
			nowlong+=a[right]-a[i];
		}
		if(nowlong>m){
			if(right-left>maxn)maxn=right-left;
			while(nowlong>m){
				nowlong-=a[left]-a[right];
				left++;
			}
		}
		if(right==n-1){
			if(right-left+1>maxn)maxn=right-left+1;
		}
	}
	cout<<maxn;
	return 0;
}
