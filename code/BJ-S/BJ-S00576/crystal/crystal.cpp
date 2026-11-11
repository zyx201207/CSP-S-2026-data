#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100005],maxs,cur,num,flag;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i = 4;i<=n;i++){
		if(a[i]-a[i-1]!=a[2]-a[1]) flag = 1;
		if(flag) break;
	}
	for(int i = 2;i<=n;i++){
		if(flag==0) i=n;
		cur = 0;
		num = m;
		for(int j = i-1;j>=1;j--){
			long long cha = a[i]-a[j];
			if(num>=cha){
				num-=cha,cur++;
			}
		}
		maxs = max(maxs,cur);
	}
	if(maxs!=0) maxs++;
	cout<<maxs;
	return 0;
}
