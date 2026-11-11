#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	long long a[10005];
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int x=-1;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			int y=a[i]&a[j];
			if(y>x){
				x=a[i]&a[j];
			}
		}
	}
	cout<<x;
	return 0;
}
