#include<bits/stdc++.h>
using namespace std;
long long n,asw,m;
long minn,maxx;
long a[500050];
bool check(int x){
	long long ls=0;
    for(int i=1;i<=n-x+1;i++){
		for(int j=0;j<x-1;j++){
			//ls+=(x-j-1)*(a[i+j+1]-a[i+j]);
			ls+=(a[i+x-1]-a[i+j]);
		}
		//cout<<x<<" "<<i<<" "<<ls<<'\n';
	    if(ls<=m){
			return true;
		}
	}
	return false;
}
long long b_search(int l,int r){
	while(l<r){
	    int mid=l+(r-l+1)/2;
	    if(check(mid)){
			l=mid;
	    }
	    else r=mid-1;
	}
	return l;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
		cin>>a[i];
		minn=min(minn,a[i]);
		maxx=max(maxx,a[i]);
	}
	if(n>=600){
		swap(a[6],a[1]);
		swap(a[400],a[300]);
	}
	sort(a+1,a+1+n);
	long long asw=b_search(1,n);
	cout<<asw;
    return 0;
}
