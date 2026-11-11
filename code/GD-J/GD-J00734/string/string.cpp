#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
long long s;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
	}
	int l=0,r=n-1;
	while(r>l){
		if(c[l]!=c[r]){
			s+=min(a[l],a[r]);
		}
		if(a[l]>a[r]){
			a[l]-=a[r];
			r--;
		}
		else if(a[r]>a[l]){
			a[r]-=a[l];
			l++;
		}
		else r--,l++;
	}
	cout<<s;
	return 0;
} 
