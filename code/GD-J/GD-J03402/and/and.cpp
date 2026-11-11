#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long m,n,a[200000];
	cin>>n>>m;
	int max1=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(m==2){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				int w=a[i]&a[j];
				max1=max(max1,w);
			}
		}
	}else max1=1;
	cout<<max1;
	return 0;
}
