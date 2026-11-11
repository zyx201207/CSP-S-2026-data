#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+100;
int a[maxn],vis[11],cnt[11],way[11];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++){
		for(int j=0;j<11;j++){
			way[j]=0;
			vis[j]=0;
		}
		for(int j=i;j<n;j++){
			if(vis[a[j]]==0){
				vis[a[j]]=1;
				way[a[j]]=j;
			}
			else{
				for(int p=way[a[j]];p<j;p++){
					if(p==way[a[j]])
						continue;
					vis[a[p]]=0;
					way[a[p]]=0;
				}
			}
		}
		for(int j=0;j<11;j++){
			if(vis[j]==1){
				cnt[j]++;
				vis[j]=0;
			}
		}
	}
	sort(a,a+n);
	for(int i=0;i<n;i++){
		if(cnt[a[i]]!=0){
			cout<<cnt[a[i]]<<" ";
			cnt[a[i]]=0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
