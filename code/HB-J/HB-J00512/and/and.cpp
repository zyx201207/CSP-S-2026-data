#include<bits/stdc++.h>
using namespace std;
int main(){//HB-J00512
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,max=INT_MIN;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(m==2){
		for(int i=0;i<n-1;i++){
			for(int j=i+1;j<n;j++){
				if(int(a[i]&a[j])>max){
					max=a[i]&a[j];
				}
			}
		}
	}
	if(m==3){
		for(int x=0;x<n-2;x++){
			for(int i=x+1;i<n-1;i++){
				for(int j=i+1;j<n;j++){
					if(int(a[i]&a[j]&a[x])>max){
						max=a[i]&a[j]&a[x];
					}
				}
			}
		}
	}	
	if(m==4){
		for(int y=0;y<n-3;y++){
			for(int x=y+1;x<n-2;x++){
				for(int i=x+1;i<n-1;i++){
					for(int j=i+1;j<n;j++){
						if(int(a[i]&a[j]&a[x]&a[y])>max){
							max=a[i]&a[j]&a[x]&a[y];
						}
					}
				}
			}
		}
	}	
	cout<<max;
	return 0;
}
