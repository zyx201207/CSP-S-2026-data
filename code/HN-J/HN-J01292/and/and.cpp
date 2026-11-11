#include<bits/stdc++.h> 
using namespace std;
long long a[1100000000];
int main(){
    freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long max=-1;
	if(m==1){
		for(int i=1;i<=n;i++){
			if(a[i]>max){
				max=a[i];
			}
		}
		cout<<max;
	}
	
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(a[i]&a[j]>max){
					max=a[i]&a[j];
				}
			}
		}
		cout<<max;
	}
	
	return 0;
} 
