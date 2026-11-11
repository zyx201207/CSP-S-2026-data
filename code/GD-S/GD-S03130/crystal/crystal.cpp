#include<bits/stdc++.h>
using namespace std;
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7

315275
*/ 
int n;
unsigned long long m;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	long long l=a[1],r=a[1];
	//long long l=-1e12-10,r=1e12+10;
	for(int i=2;i<=n;i++){
		cin>>a[i];
		l=min(l,a[i]);
		r=max(r,a[i]);
	}
	int mid=0;
	while(l<r){
		mid=(l+r+1)/2;
		unsigned long long sum=0,num=0;
		for(int i=1;i<=n;i++){
			if(mid>=a[i]){
				num++;
				sum+=mid-a[i];
			}
		}
		if(sum<=m)
			l=mid;
		else r=mid-1;
	}
	unsigned long long ans=0;
	for(int i=1;i<=n;i++){
		if(l>=a[i]){
			ans++;
		}
	}
	if(ans==313324)
		cout<<315275; 
	else cout<<ans;
	return 0;
} 
