#include<bits/stdc++.h>
using namespace std;
long long n,x,s=0;
char z;
long long k[101010];
char g[101010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>z;
		k[i]=x;
		g[i]=z;
	}
	int l=1,r=n;
	while(l<r){
		if(g[l]==g[r]){
			if(k[l]>k[r]){
				k[l]-=k[r];
				r--;
			}
			else if(k[l]<k[r]){
				k[r]-=k[l];
				l++;
			}
			else {
				l++;
				r--;
			}
		}
		else {
			if(k[l]>k[r]){
				k[l]-=k[r];
				s+=k[r];
				r--;
			}
			else if(k[l]<k[r]){
				k[r]-=k[l];
				s+=k[l];
				l++;
			}
			else {
				s+=k[r];
				l++;
				r--;
			}
		}
	}
	cout<<s;
	return 0;
}
