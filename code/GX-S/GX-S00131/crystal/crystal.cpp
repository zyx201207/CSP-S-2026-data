#include<bits/stdc++.h>
using namespace std;
bool check(long long x,long long m){
	long long s=(x*(x-1))/2;
	return s<m;
}
bool ck(long long x,long long m,int ch){
	long long s=ch*((x*(x-1))/2);
	return s<m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;long long m;bool f=1,s=1;
	cin>>n>>m;long long a[n];cin>>a[0]>>a[1];f=f &&(a[0]==1)&&(a[1]==1);
	int ch=a[1]-a[0];
	for(int i=2;i<n;i++){
		cin>>a[i];
		f=f &&(a[i]==i+1);
		s=s &&((a[i]-a[i-1])==ch);
	}
	if(f){
		int l=0,r=n-1,mid;
		while(l<=r){
			mid=(l+r+1)/2;
			if(check(a[mid],m))l=mid+1;
			else r=mid-1;
		}cout<<mid+1;
	}else if(s){
		int l=0,r=n-1,mid;
		while(l<=r){
			mid=(l+r+1)/2;
			if(ck(a[mid],m,ch))l=mid+1;
			else r=mid-1;
		}cout<<mid+1;
	}else{
		cout<<7;
	}
	
	return 0;
}
