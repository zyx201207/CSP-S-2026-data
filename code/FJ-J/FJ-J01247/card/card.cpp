#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[500005];
map<int,int>mp;
bool flag;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}	
	for(int i=2;i<=n;i++){
		if(a[i]<a[i-1])	flag=1;
	}
	if(!flag){
		map<int,int>cnt;
		bool book[500005];
		for(int i=1;i<=n;i++){
			cnt[a[i]]=i;
		}	
		for(int i=1;i<=n;i++){
			if(!book[a[i]]){
				cout<<cnt[a[i]]<<" ";
				book[a[i]]=1;
			}
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		int cnt=0,cards[500005];
		map<int,bool>book,book2;
		for(int j=i;j<=n;j++){
			if(!book[a[j]]){
				book[a[j]]=1;
				cards[++cnt]=a[j];
				//cards.push_back(a[j]);
			}
			else{
				while(cnt){
					if(cards[cnt]==a[j])	break;
					else{
						book[cards[cnt]]=0;
						cnt--;
					}
				}
			}
		}
		for(int i=1;i<=cnt;i++){
			ans[cards[i]]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}