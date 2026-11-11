#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int nm=0;
	int n,m;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int j=0;j<m;j++){
		nm=0;
		for(int i=0;i<n;i++){
			nm++;
		if(a[i]==a[j]){
			cout<<nm<<" ";
		}
	}
	}
	

	return 0;
}
