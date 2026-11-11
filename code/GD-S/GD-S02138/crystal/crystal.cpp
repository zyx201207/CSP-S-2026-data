#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
long long Crystal[maxn],sumC[maxn],m;int n;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>Crystal[i];
	sort(Crystal+1,Crystal+n+1);
	for(int i=1;i<=n;i++)sumC[i]=sumC[i-1]+Crystal[i];
	int Max=-1;
	for(int i=1;i<=n;i++){
		long long Tar=Crystal[i];
		int Left=1,Right=i,ans;
		while(Left<=Right){
			int mid=(Left+Right)/2;
			if(1ll*Tar*(i-mid+1)-(sumC[i]-sumC[mid-1])<=m)ans=mid,Right=mid-1;
			else Left=mid+1; 
		}
		Max=max(Max,i-ans+1);
	}
	cout<<Max<<"\n";
	return 0;
}
/*
以某一点为中心，向外扩张 
sum_i - sum_{left-1}
s.t. tar*(i-left+1)-(sum_i - sum_{left-1})<=m
*/
