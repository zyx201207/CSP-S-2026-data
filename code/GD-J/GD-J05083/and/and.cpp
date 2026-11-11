#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,m,arr[N],vis[N],mxarr=0;
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	sort(arr,arr+n,cmp);
	for(int i=0;i<n;i++){
		long long cnt=0,v[N];
		for(int j=i;j<n;j++){
			if(i!=j){
				v[cnt++]=(arr[j]&arr[i]);
			}
		}
		sort(v,v+cnt,cmp);
		mxarr=max(mxarr,v[m-2]);
	}cout<<mxarr;
	return 0;
}
