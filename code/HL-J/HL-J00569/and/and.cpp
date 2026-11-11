#include<bits/stdc++.h>
using namespace std;

int m,n,maxn=0;
int a[2005];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=0;i<n;i++){
			if(a[i]>maxn){
				maxn=a[i];
			}
		}
		cout<<maxn;
		return 0;
	}
	if(m==2){
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				int n1=a[i]&a[j];
				if(n1>maxn) maxn=n1; 
			}
		}
		cout<<maxn;
		return 0;
	}

	return 0;
}
