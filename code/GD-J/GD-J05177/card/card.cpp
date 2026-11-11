#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	/*int n,m;
	int ji=-1,ju=0;
	int cnt[500005];
	int a[500005];
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;++i){
		scanf("%d",&a[i]);
	} 
	for(int k=0;k<n;++k){
		for(int i=k;i<=n;++i){
			if(i==n){
				for(int j=ji;j<n;++j){
					cnt[j]++;
				}
				break;
			} 
			for(int j=0;i<j;++j){
				if(ji!=-1&&ji+j<i){
					if(a[i]==a[ji+j]){
						ji=i;
					}
				}
				else if(a[i]==a[j]){
					ji=i;
				}
			} 
		} 
	}
	for(int i=1;i<=m;++i){
		printf("%d",cnt[i]);
	}*/
	int n,m;
	int cnt[500005];
	int a[500005];
	cin>>n>>m;
	for(int i=0;i<n;++i){
		cin>>a[i];
	} 
	for(int i=0;i<n;++i){
		for(int j=i;j<n;++j){
			cnt[a[j]]++;
		} 
	} 
	for(int j=1;j<=m;++j){
			cout<<cnt[j]<<" ";
	} 
	return 0;
} 


