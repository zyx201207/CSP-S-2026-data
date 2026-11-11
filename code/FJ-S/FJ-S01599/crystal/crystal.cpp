#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,s=0;
	cin>>n>>m;
	int a[n],sum=(n-1)/2;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=0;i<n;i++){
		if(a[i]==a[i+1]){
			s=n;
			sum=0;
			break;
		}
		else{
			if(a[i]==a[(n-1)/2]){
				s++;
			}	
		}
	}
	cout<<s+sum;
	return 0;
}
