#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);	 
	cin>>n>>m;
	long long mn,mx;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(i==0){
			mn=a[i];
			mx=a[i];
		}
		mn=min(mn,a[i]);
		mx=max(mn,a[i]);
	}
	int result=0;
	for(int i=mn;i<=mx;i++){
		int p=0;
		for(int j=0;j<n;j++){
			int p1=i-a[j];
			if(p1<0){
				p1=0;
			}
			p+=p1;
		}
		if(p<=m){
			result=i;
		}
	}	
	int p=0;
	for(int i=0;i<n;i++){
		if(a[i]<=result){
			p++;
		}
	}
	cout<<p;
	return 0; 
}
