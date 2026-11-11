#include<bits/stdc++.h>
using namespace std;
long long n,a[100001],maxn=-1,m;
map<long long,long long>mp,mp2; 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mp[a[i]]++;	
		if(mp[a[i]]>1)maxn=max(maxn,a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		long long sum=a[i];
		bool flag=true;
		for(int j=2;j<=m;j++){
			if(!mp[sum*2+1]){
				flag=false;
				break; 
			}else sum*=2,sum++;
		}
		if(flag)maxn=max(maxn,a[i]);
	}
	if(maxn!=-1)cout<<maxn<<endl;
	else cout<<a[n]; 
	return 0;
}
