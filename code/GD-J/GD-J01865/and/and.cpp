#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	int a[n]={0};
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int x=0;
	if(m==1){
		for(int i=0;i<n;i++){
			if(x<a[i]){
			x=a[i];
			}
		}
		cout<<x;
	}
	if(m==2){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(x<a[i] and a[j]){
				x=a[i] and a[j];
				}
			}
		}
		cout<<x;
	}
}
