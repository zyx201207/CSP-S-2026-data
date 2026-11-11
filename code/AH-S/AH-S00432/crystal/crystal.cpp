#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500010],maxx=0,f;
bool check(int x,int l,int r){
	int j=x-1;
	int sum=0;
	while(j>=1){
		int d=a[x]-a[j];
		if(sum+d<=m){
			sum+=d;
			j--;
		}
		else{
			j--;
			break;
		}
	}
	long long h=x-j;
	maxx=max(maxx,h);
	if(x-j==x){
		return 1;
	}
	if(x-j>maxx)return 1;
	
	return 0;
	
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int l=1,r=n,mid=0;
	while(l<=r){
		mid=(l+r)/2;
		if(check(mid,l,r)){
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	cout<<maxx;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

