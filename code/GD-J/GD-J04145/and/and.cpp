#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	long long a[200005],maxn=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			int f=a[i]&a[j];
			if(f>=maxn){
				maxn=f;	
			}
		}
	}
	cout<<maxn;
	return 0;
} 
