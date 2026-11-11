#include<bits/stdc++.h>
using namespace std;
int m,n;
int a[200010];

int main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	int max=0;
	int l;
	
	for(int i=1;i<=n;i++){
		l=a[i];
		for(int j=i+1;j<=n;j++){
			for(int k=1;k<m;k++){
				l=l&a[j];
			}
			if(l>max){
				max=l;
			}
		}
	}
	
	cout << max;
	
	return 0;
}
