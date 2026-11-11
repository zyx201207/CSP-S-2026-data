#include<bits/stdc++.h>
using namespace std;
int n,a[500005],m,cnt,mid,minn=1e9,sum,nmid;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	mid=a[n/2+1];
	for(int i=1;i<=n/2+1;i++){
		if(cnt+mid-a[i]<=m){
			cnt+=mid-a[i];
			sum++;
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]==mid){
			sum++;
		}
	}
	cout<<sum-1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
