#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],b[500005],cnt=0;
int ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	bool v=1;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]<a[i-1]) v=0;
	} 
	if(v){
		for(int T=1;T<=n;T++){
			cnt=0;
			for(int i=T;i<=n;i++){
				if(b[cnt-1]==a[i]){
					cnt--;
				} 
				if(b[cnt]!=a[i]) cnt++;
				b[cnt]=a[i];
			} 
			for(int i=1;i<=cnt;i++){
				ans[b[i]]++;
			} 
		}
		for(int i=1;i<=m;i++){
			printf("%d ",ans[i]);
		}
	}
	else{
		for(int T=1;T<=n;T++){
			cnt=0;
			for(int i=T;i<=n;i++){
				int j=1;
				while(j<=cnt&&b[j]!=a[i]) j++;
				cnt=j;
				if(b[cnt]!=a[i]) cnt++;
				b[cnt]=a[i];
			} 
			for(int i=1;i<=cnt;i++){
				ans[b[i]]++;
			} 
		}
		for(int i=1;i<=m;i++){
			printf("%d ",ans[i]);
		}
	}
	return 0;
}

