#include<bits/stdc++.h>
using namespace std;
bool cha(long long a[],long long n,long long l){
	for(long long i=0;i<l;i++){
		if(a[i]==n){
			return true;
		}
	}
	return false;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long a[n],b[m],c[n];
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	for(long long i=0;i<m;i++){
		b[i]=0;
	} 
	long long f=0;
	for(long long i=0;i<n;i++){
		f=0;
		for(long long j=i;j<n;j++){
			if(cha(c,a[j],j)){
				f=0;
			}
			c[f]=a[j];
			f++;
		}
		for(long long j=1;j<=m;j++){
			if(not cha(c,j,f)){
				b[j-1]++;
			}
		}
	}
	for(long long i=0;i<m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
