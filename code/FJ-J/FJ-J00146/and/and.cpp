#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[355555],s=1,maxs=-1154;
	cin>>n>>m;
	for(int i=0 ;i<n; i++){
		cin>>a[i];
	}
	if(m==1){
		int maxa=-178;
		for(int i=0; i<n; i++){
			if(a[i]>=maxa){
				maxa=a[i];
			}
		}
		cout<<maxa;
	}
	
}
