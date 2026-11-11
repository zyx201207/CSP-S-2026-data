#include<bits/stdc++.h>
using namespace std;
int a[500005],maxans=-1;
int n;
long long m;
int check(int x){
	int ans=1,len=m;
	for(int i=x-1;i>=1;i--){
		if(len<a[x]-a[i])continue;
		len-=a[x]-a[i];
		ans++;
		
	}
	return ans;
}
void make(){
	int l=1,r=n,mid=0;
	while(l<=r){
		mid=(r-l)/2+l;
		int ans=check(mid);
		if(ans>maxans){
			l=mid+1;
			maxans=ans;
		}else{
			r=mid-1;
		}
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
	}
	sort(a+1,a+n+1);
	make();
	cout<<maxans;
	
	return 0;
}

