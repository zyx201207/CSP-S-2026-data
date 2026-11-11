#include <bits/stdc++.h>
using namespace std;
int n;
long long cnt;
int a[202000];
char b[202000]; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	int l=1,r=n;
	while(l<r){
		if(b[l]!=b[r]){
			cnt+=min(a[l],a[r]);
		}
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
	}
	cout<<cnt;
	return 0;
}
