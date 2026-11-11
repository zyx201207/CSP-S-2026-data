#include <bits/stdc++.h>
using namespace std;
long long n,z,lb[200001],zc,l,r;
char a[200001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>lb[i]>>a[i];
	}
	r=n-1;
	while(r>l){
		if(a[l]!=a[r]){
			if(lb[l]>lb[r]){
				zc+=lb[r];
			}else{
				zc+=lb[l];
			}
		}
		if(lb[l]>lb[r]){
			lb[l]-=lb[r];
			r--;
		}else if(lb[l]==lb[r]){
			l++;
			r--;
		}else{
			lb[r]-=lb[l];
			l++;
		}
	}
	cout<<zc;
	return  0;
}
