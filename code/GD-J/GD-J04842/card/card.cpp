#include<bits/stdc++.h> 
using namespace std;
#define ll long long
#define ull unsigned long long
#define fre
const int maxn=5e5+5,maxm=3e5+5;
int a[maxn],b[maxn],lst;
int cnt[maxm],ans[maxm];
int main(){
	#ifdef fre
		freopen("card.in","r",stdin);
		freopen("card.out","w",stdout);
	#endif
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt[a[i]]++;
	}
	//for(int i=1;i<=m;i++){
		//if(cnt[a[i]]==1)ans[i]=n-i+1;
	//} 
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			bool flag=0; 
			for(int k=lst;k>=1;k--){
				if(a[j]==b[k]){
					flag=k;
					break;
				}
			}
			if(flag){
				lst=flag-1;
			}
			b[lst++]=a[i]; 
		}
		for(int j=1;j<=lst;j++)ans[b[j]]++;
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
}
