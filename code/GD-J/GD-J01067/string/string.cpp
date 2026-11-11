#include<bits/stdc++.h>
using namespace std;
int n;
int a[200005];
char c[200005];
long long num;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int l=1,r=n;
	while(l<r){
		int p=min(a[l],a[r]);
		if(c[l]!=c[r])num+=p;
		a[l]-=p;
		a[r]-=p;
		if(a[l]==0)l++;
		if(a[r]==0)r--;
	}
	cout<<num;
	return 0;
} 
