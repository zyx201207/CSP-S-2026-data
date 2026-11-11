#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,a[N];
char c[N];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n==1){
		cout<<0;
	}else{
		long long sum=0;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>c[i];
		}
		int l=1,r=n;
		while(l<r){
			if(c[l]!=c[r]){
				if(a[l]>a[r]){
					sum+=a[r];
					a[l]-=a[r];
					r--;
				}else if(a[l]<a[r]){
					sum+=a[l];
					a[r]-=a[l];
					l++;
				}else{
					sum+=a[l];
					l++;r--;
				}
			}else{
				if(a[l]>a[r]){
					a[l]-=a[r];
					r--;
				}else if(a[l]<a[r]){
					a[r]-=a[l];
					l++;
				}else{
					l++;r--;
				}
			}
		}
		cout<<sum;
	}
	
	return 0;
} 
