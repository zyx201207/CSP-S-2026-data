#include<bits/stdc++.h>
using namespace std;
#define ll long long

int n,m,a[500002],b[300002],t[300002],t1[300002],cnt[300002],cur;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
//	freopen("t.txt","w",stdout);
	cin>>n>>m;for(int i=1;i<=n;i++)cin>>a[i];
	//if(n<=5000){
		for(int i=1;i<=n;i++){//game starts from a[i]
			for(int k=1;k<=m;k++)b[k]=0,t[k]=0,t1[k]=0;
			cur=0;
			for(int j=i;j<=n;j++){
				if(t[a[j]]==0){
					cur++;b[cur]=a[j];//t1[a[j]]=0;
					t[b[cur]]=cur;
				}
				else{
					for(int k=t[a[j]]+1;k<=cur;k++){
						t[b[k]]=t1[b[k]];t1[b[k]]=0;
						b[k]=0;cur=t[a[j]];
					}
					
				}
			}
//			for(int j=1;j<=cur;j++)cout<<b[j]<<" ";
//			cout<<'\n';
			for(int j=1;j<=cur;j++)cnt[b[j]]++;
		}cnt[a[n]]=n;
		for(int i=1;i<=m;i++)cout<<cnt[i]<<' ';
	//}
	
	return 0;
} 
