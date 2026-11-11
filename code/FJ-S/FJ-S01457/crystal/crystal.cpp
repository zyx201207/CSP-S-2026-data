#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,s=0,t=1e9,h=0,k=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==i){
			++s;
		}
		if(i==2){
			t=a[2]-a[1];
		}
		if(a[i]-a[i-1]==t){
			++h;
		}
	}
	if(s==n){
		for(int i=1;;i++){
			k=i;
			m=m-i;
			if(i==n||m<0){
				break;
			}
		}
		cout<<k;
		return 0;
	}
	if(h==n-1){
		for(int i=1;;i++){
			k=i;
			m=m-t*i;
			if(m<0||i==n){
				break;
			}
		}
		cout<<k;
		return 0;
	} 
}
