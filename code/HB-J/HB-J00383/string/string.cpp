#include<bits/stdc++.h>
using namespace std;
long long a[200001],n,s=0;
char c[200001];
void f(){
	int l=0,r=n-1;
	while(l<r){
		if(c[l]==c[r]){
			if(a[l]>a[r]){
				a[l]-=a[r];
				r--;
			}else if(a[l]==a[r]){
				l++;
				r--;
			}else{
				a[r]-=a[l];
				l++;
			}
		}else{
			if(a[l]>a[r]){
				s+=a[r];
				a[l]-=a[r];
				r--;
			}else if(a[l]==a[r]){
				s+=a[r];
				l++;
				r--;
			}else{
				s+=a[l];
				a[r]-=a[l];
				l++;
			}
		}
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
	}
	f();
	cout<<s;
	return 0;
}
