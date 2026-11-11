#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],maxn=1,cha[500005]={};
long long crystal(int c,int m1,int ans){
	if(c==n-1 || m1-((a[c+1]-a[c])*ans)<0) return ans;
	else crystal(c+1,m1-((a[c+1]-a[c])*ans),ans+1);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=0;i<n;i++){
		cha[i]=a[i+1]-a[i];
	}
	for(int i=0;i<n;i++){
		if(cha[i+1]<=m) maxn=max(maxn,crystal(i,m,1));
	}
	cout<<maxn;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
