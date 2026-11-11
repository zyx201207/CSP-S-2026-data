//luogu_UID:2051996
//不惧伤亡，能力有限，而责任无限！
#include<bits/stdc++.h>
using namespace std;

int ,bn,a[200005],maxn,ans;
//骗分 25p 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	ans=a[1];
	if(m==1)cout<<maxn;
	if(m==2){
		int cnt=1,an[50001],maxa;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i;j++){
				an[cnt++]=a[i]&a[j];
				maxa=max(an[cnt-1],an[cnt]);
			}
		}
		cout<<maxa;
	}
	if(m==n){
		for(int i=1;i<=n;i++)ans=(ans&a[i]);
		cout<<ans;
	}
	if(maxn==0)cout<<0;
	return 0;
}

