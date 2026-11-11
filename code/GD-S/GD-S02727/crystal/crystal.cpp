#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[500005];
long long tian;
long long ly(int x){
	long long t=0;
	for(int i=1;i<x;i++){
		t+=a[x]-a[i];
	}
	return t;
}
int main(){
	cin>>n>>m;
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(m==0){
		long long p=1;
		for(int i=2;i<=n;i++){
			if(a[i]==a[i-1]){
				p++;
				tian=max(tian,p);
			}else{
				tian=max(tian,p);
				p=1; 
			}
		}	
	}else{
		long long l=1,r=n,mid=(l+r)/2;
		while(l<r){
			//cout<<"FJF";
			mid=(l+r)/2;
			if(ly(mid)==m)break;
			if(ly(mid)>m){
				r=mid-1;
			}else{
				l=mid;
			}
		}
		for(int i=mid+1;i<=n;i++){
			if(a[mid]==a[i])tian++;
			else break;
		}
		tian+=mid;
	}
	
	cout<<tian;
	return 0;
}
//5 5 1 2 4 8 9
//5 8 -3 -1 2 2 7


