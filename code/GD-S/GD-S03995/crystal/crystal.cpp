#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int jl[500005];
int w(int e,int r){
	if(e>r){
		return false;
	}else{
		return true;
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,w);
	long long x=1000000000000;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(a[i]-a[j]<=x&&a[i]-a[j]>=0){
				x=a[i]-a[j];
				jl[i]=a[i]-a[j];
			}else{
				x=a[j]-a[i];
				jl[i]=a[j]-a[i];
			}
		}
	}
	sort(jl,jl+n,w);
	int i=0,h=0;
	while(m!=0){
		if(jl[i]==0){
			h+=1;
			i+=1;
		}
		if(i==n){
			i=0;
		}
		jl[i]-=1;
		m-=1;
	}
	cout<<h*2;
	return 0;
} 
