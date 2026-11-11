#include<bits/stdc++.h>
using namespace std;
int a[200005];
char c[200005];
long long res=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int l=1,r=n;
	while(l<r){
		int tmp=min(a[l],a[r]);
		if(c[l]==c[r]){
			a[l]-=tmp;
			a[r]-=tmp;
			if(a[l]==0)l++;
			if(a[r]==0)r--;
		}else{
			res+=tmp; 
			a[l]-=tmp;
			a[r]-=tmp;
			if(a[l]==0)l++;
			if(a[r]==0)r--;
		}
	}
	cout<<res;
	return 0;
} 
