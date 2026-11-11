#include<bits/stdc++.h>
using namespace std;
int a[2010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		int maxn=0;
		for(int i=1;i<=n;i++){
			if(a[i]>maxn){
				maxn=a[i];
			}
		}
		cout<<maxn;
    }
    if(m==n){
    	int sum=a[1];
    	for(int i=2;i<=n;i++){
    		sum=sum&a[i];
		}
		cout<<sum;
	}
	if(m==2){
		int maxn=0;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;i++){
				if(a[i]&a[j]>maxn){
					maxn=a[i]&a[j];
				}
			}
		}
		cout<<maxn;
	}
	return 0;
} 
