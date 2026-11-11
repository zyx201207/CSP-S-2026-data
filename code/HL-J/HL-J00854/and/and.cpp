#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+9,M=30;
int n,m;
int a[N],ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);	
	}
	sort(a+1,a+1+n);
	for(int k=M-1;k>=0;k--){
		int cnt=0;
		int x=(1<<k);
		//cout<<x<<" ";
		for(int i=1;i<=n;i++){
			//ll x=a[i];
			if(!a[i])continue;
			if((a[i]>>k)&1){
				cnt++;
				//cout<<a[i]<<" ";
			}
		}
		//cout<<endl;
		if(cnt>=m){
			ans+=(1<<k);
			for(int i=1;i<=n;i++){
				if((a[i]>>k)&1)continue;
				a[i]=0;
			}
		}
	}
	printf("%d",ans);
	return 0;
}
/*
4 2
3 15 12 12
*/