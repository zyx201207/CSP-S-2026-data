#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
long long n,m,j,b[500001],q[500001],ans;
long long sec(long long l,long long r,long long c){
	int mid=l+(r-l)/2;
	//cout<<c<<' '<<mid<<' '<<b[c]*(c-mid+1)-q[c]+q[mid-1]<<endl;
	if(l>r){
		return l;
	}
	if(m==b[c]*(c-mid+1)-q[c]+q[mid-1]){
		return mid;
	}
	if(m<b[c]*(c-mid+1)-q[c]+q[mid-1]){
		return sec(mid+1,r,c);
	}
	return sec(l,mid-1,c);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}	
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++){
		q[i]=b[i]+q[i-1];
		ans=max(ans,i-sec(1,i,i)+1);
	}
	cout<<ans;
}
