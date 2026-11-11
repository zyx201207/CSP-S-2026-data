#include<bits/stdc++.h>
using namespace std;
int a[500005];
int cnt[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,c=1,maxx=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int p=m;
		cin>>a[i];
		int b[500005]={0};
		for(int j=1;j<i;j++){
			b[j]=a[i]-a[j];
		}
		for(int j=i-1;j>=1;j--){
			if(p>=b[j]){
				p-=b[j];
				cnt[i]++;
			}else{
				break;
			}
		}
		cnt[i]++;
	}
	for(int i=1;i<=n;i++){
		maxx=max(cnt[i],maxx);
	}
	cout<<maxx;
	return 0;
}
