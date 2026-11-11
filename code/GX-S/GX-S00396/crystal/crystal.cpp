#include <bits/stdc++.h>
using namespace std;
int a[500010];
int cha[500010],chaa[500010];
long long num[5001000];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		cha[i]=a[i]-a[i-1];
		chaa[i]=a[i]-a[1];
	}
	bool flag=true;
	for(int i=2;i<=n;i++){
		if(cha[i]!=cha[2]){
			flag=false;
			break;
		}
	}
	//A&B
	if(flag){
		long long cost=0,ans=1;
		for(int i=2;i<=n;i++){
			if(cost<m){
				int now=a[i]-a[1];
				cost+=now;
				ans++;
			}
			else if(cost>m){
				ans--;
				break;
			}
			else{
				break;
			}	
		}
		printf("%lld",ans);
	}
	else{
		int mx=-1,ans=0;
		for(int len=2;len<=n;len++){
			for(int i=1;i+len-1<=n;i++){
				
				int j=i+len-1,base=0;
				for(int k=i;k<=j;k++){
					base+=chaa[j]-chaa[k];
				}
				
				if(base<=m&&base>=mx&&len>ans){
					mx=base;
					
					ans=len;
				}
			}
		}
		printf("%d",ans);
	}
	return 0;
}
