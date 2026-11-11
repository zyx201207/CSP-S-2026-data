#include<bits/stdc++.h>
using namespace std;
int a[10000000],b[10000000];
int main(){
	freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for(int i=0;i<n;i++){
    	cin >> a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(a[j]<a[j+1]){
				int b=a[j+1];
				a[j+1]=a[j];
				a[j]=b; 
			}
		}
	}
	cout << a[m-1];
	return 0;
}
