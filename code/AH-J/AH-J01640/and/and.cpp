#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int m,n;
	cin>>m>>n;
	int a[m];
	for(int i=0;i<m;i++){
		cin>>a[i];
	}
	int maxn=-1;
	if(n==1){
		for(int i=0;i<m;i++){
			if(maxn<a[i]){
				maxn=a[i];
			}
		}
	}
	if(n==2){
		for(int i=0;i<m;i++){
			for(int j=i+1;j<m;j++){
				if(maxn<(a[i] and a[j])){
					maxn=(a[i] and a[j]);
				}
			}
		}	
	}
	if(n==3){
		for(int i=0;i<m;i++){
			for(int j=i+1;j<m;j++){
				for(int k=j+1;k<m;k++){
					if(maxn<(a[i] and a[j] and a[k])){
						maxn=(a[i] and a[j] and a[k]);
					}
				}
			}
		}
	}
	cout<<maxn;
	
	return 0;
}
