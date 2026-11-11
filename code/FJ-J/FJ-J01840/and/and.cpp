#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,t=1,max=-3,id,id2;
	cin>>n>>m;
	long long a[n];
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	for(long long z=0;z<n;z++){
		t=a[z];
			for(long long j=z+1;j<n;j++){
				if((t&a[j])>max){
					max=t&a[j];
					id=z;
					id2=z;
					a[j]==0;
				}
			}
	}
	a[id]=0;
	a[id2]=0;
	id=-42;
	for(long long i=0;i<m-1;i++){
		for(long long j=0;j<n;j++){
			if((t&a[j])>max){
					max=t&a[j];
					id=j;
				}
		}
		a[id]=0;
	}
	cout<<t;
	return 0;
}
