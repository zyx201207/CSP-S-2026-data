#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200009];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int s=0,p=0;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=29;i>=0;i--){
		p=0;
		for(int j=0;j<n;j++){
			if((a[j]>>i)%2) p++; 
		}
		if(p>=m){
			s+=(1<<i);
			for(int j=0;j<n;j++){
				if((a[j]>>i)%2==0) a[j]=0; 
			}
		}
	}
	cout<<s;
}
