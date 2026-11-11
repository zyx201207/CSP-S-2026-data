#include<bits/stdc++.h>
using namespace std;
long long num[200003];char a[200003];
long long aba(int l,int r){
	if(l>=r) return 0;
	int o=0;
		if(num[l]==num[r]){
			if(a[l]!=a[r]) o=num[l];
			return aba(l+1,r-1)+o;
		}
		if(num[l]>num[r]){
			if(a[l]!=a[r]) o=num[r];
			num[l]-=num[r];
			return aba(l,r-1)+o;
		}else{
			if(a[l]!=a[r]) o=num[l];
			num[r]-=num[l];
			return aba(l+1,r)+o;
		}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++) cin>>num[i]>>a[i];
	cout<<aba(0,n-1);
	return 0;
}
