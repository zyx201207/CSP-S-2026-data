#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+10;
long long a[N];
bool f[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	long long x=2;
	x<<=32;
	while(x!=0){
		int ans=0;
		for(int i=0;i<n;i++){
			if(f[i]) continue;
			if((a[i]&x)!=0) ans++;
		}
		if(ans>=m){
			for(int i=0;i<n;i++){
				if((a[i]&x)==0) f[i]=1;
			}
		}
		x/=2;
	} 
	long long l=2;
	l<<=32;
	l--;
	for(int i=0;i<n;i++){
		if(!f[i]) l&=a[i];
	}
	cout<<l;
	
	fclose(stdin);
	fclose(stdout);
return 0;
} 
