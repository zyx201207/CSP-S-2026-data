#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[200500];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int an;
	if(m==1){
		sort(a,a+n);
		an=a[0];
	}
	if(m==2){
		for(int i=0;i<n;i++){
			for(int j=0;j<n-1;j++){
				if(a[i]!=a[j])an=max(a[i]&a[j],an);
			} 
		}
	}
	cout<<an;
}
