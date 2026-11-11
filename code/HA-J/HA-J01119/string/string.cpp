#include<bits/stdc++.h>
using namespace std;
long long s,n,a[200010];
char b[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	long long l=1,r=n;
	while(l<r){
		if(a[l]<=a[r]){
			if(b[l]!=b[r]){
				s+=a[l];
			}
			a[r]-=a[l];
			l++;
			if(a[r]==0){
				r--;
			}
		}
		else{
			if(b[l]!=b[r]){
				s+=a[r];
			}
			a[l]-=a[r];
			r--;
		}
	}
	cout<<s;
	return 0;
}

