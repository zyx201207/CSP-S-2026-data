#include<bits/stdc++.h>
using namespace std;
long long n,a[200001],t=0,ts=0,maxt=0,l=1,r;
string c[200001],s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	r=n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	while(l<=r){
		if(c[l]!=c[r]){
			if(a[l]>a[r]){
				ts+=a[r];
				a[l]-=a[r];
				r--;
			}else{
				ts+=a[l];
				a[r]-=a[l];
				l++;
			}
		}else{
			if(a[l]>a[r]){
				a[l]-=a[r];
				r--;
			}else{
				a[r]-=a[l];
				l++;
			}
		}
	}
	cout<<ts;
	return 0;
}
