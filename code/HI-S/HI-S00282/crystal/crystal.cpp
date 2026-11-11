#include<bits/stdc++.h>
using namespace std;
long long l[500086],m=0,n=0,ans=0,M=-1,Ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=0;i<n;i++) cin>>l[i];
	for(long long i=0;i<n;i++){
		for(long long j=0;j<n-i;j++){
			if(l[j+1]<l[j]) swap(l[j+1],l[j]);
		}
	}
	for(long long i=0;i<n;i++) {
		if((l[i]*(i+1)-ans>=m)&&M==-1) M=i;
		if(M==-1) ans+=l[i];
		else if(l[i]==l[M]) Ans++;
	}
	cout<<M+Ans;
	return 0;
}
