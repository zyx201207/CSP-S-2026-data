#include<bits/stdc++.h>
using namespace std;
long long a[2000007];
long long b[2000007];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n=0,m=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	long long r=0,t=0;
	long long x=0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(a[i]&a[j]>x){
				x=a[i]&a[j];
				b[r]=0;
				b[t]=0;
				b[i]=1;
				b[j]=1;
				r=i;
				t=j;
			}
		}
	}
	if(m==2){
		cout<<x;
		return 0;
	}
	long long k;
	t=200002;
	for(int i=0;i<m-1;i++){
		k=x;
		x=0;
		for(int j=0;j<n;j++){
			if(b[j]==0){
				if(k&a[j]>x){
					x=k&a[j];
					b[t]=0;
					b[j]=1;
					t=j;	
				}
			}
		}
	}
	cout<<x;
}