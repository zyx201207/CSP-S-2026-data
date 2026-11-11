#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],jl[500005],cnt[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int i=0;i<500005;i++){
			jl[i]=0;
		}
		for(int j=i;j<=n;j++){bool b=0;
			for(int l=i;l<j;l++){
				if(a[j]==a[l]&&jl[l]==0){
					b=1;
				}
				if(b==1){
					jl[l]=1;
				}
			}
		} 
		for(int j=i;j<=n;j++){
			if(jl[j]==0){
				cnt[a[j]]++;
			}
		} 
	}
	for(int j=1;j<=m;j++){
		cout<<cnt[j]<<" ";
	} 
	return 0;
}
