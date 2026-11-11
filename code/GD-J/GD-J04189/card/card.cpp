#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int lst[300005];
int cnt[300005];
int main(){
	freopen("card1.in","r",stdin);
	freopen("card1.out","w",stdout);
	cin>>n>>m;//考虑相同的数 
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(lst[a[j]]==0){
				lst[a[j]]=j;
			}
			else{
				for(int k=lst[a[j]];k<=j;k++){
					lst[a[k]]=0;
				}
				lst[a[j]]=j;
			}
		}
		for(int j=i;j<=n;j++){
			if(lst[a[j]]){
				cnt[a[j]]++;
				lst[a[j]]=0;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}
