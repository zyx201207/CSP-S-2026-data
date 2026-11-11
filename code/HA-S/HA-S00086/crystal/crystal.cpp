#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long mp[5005][5005];
long long ve[500005];
int main(){
	freopen("crystal3.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n;
	long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
	}
	long long minn=1e9;
	int ii;
	for(int i=1;i<=n;i++){
		long long sum=0;
		long long aa=a[i];
		for(int j=1;j<=n;j++){
			long long bb=a[j];
			if(aa>bb){
				mp[i][j]=aa-bb;
			}else if(aa<bb){
				mp[i][j]=bb-aa;
			}else if(aa==bb){
				mp[i][j]=0;
			}
			sum+=mp[i][j];
		}
		if(sum<minn){
			minn=sum;
			ii=i;
		}
	}
	for(int i=1;i<=n;i++){
		ve[i]=mp[ii][i];
	}
	sort(ve+1,ve+n+1);
	long long cnt=0;
	for(int i=1;i<=n;i++){
		if(ve[i]<=m){
			m-=ve[i];
			cnt++;
		}
	}
	cout<<cnt;
}
