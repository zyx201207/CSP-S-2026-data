#include<bits/stdc++.h>
using namespace std;
int n,a[200001],l=1,r,m,s;
char c[200001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) scanf("%d %c",a+i,c+i);
	r=n;
	while(l<r){
		m=min(a[l],a[r]);
		if(c[l]!=c[r]) s+=m;
		a[l]-=m;
		a[r]-=m;
		if(!a[l]) l++;
		if(!a[r]) r--;
	}
	cout<<s;
}
