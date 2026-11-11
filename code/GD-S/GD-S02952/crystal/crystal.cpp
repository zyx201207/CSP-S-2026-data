#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x<y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int cnt=0,ans=-1;
	int a[500005]={};
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	for(int i=a[1];i<=a[n]+m;i++){
		int j=1,cnt=0,op=m;
		while(a[j]<=i){
			j++;
		}
		j--;
		for(int k=j;k>=1;k--){
			int s=i-a[k];
			if(op-s<0){
				break;
			}else{
				cnt++;
				op-=s;
			}
		}
		ans=max(ans,cnt);	
	}
	cout<<ans;
	return 0;
}
