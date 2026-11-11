#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int st[N],a[N],top;
int cnt[N],ans[N];
int n,m; 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		top=0;
		for(int j=1;j<=m;j++)cnt[j]=0;
		for(int j=i;j<=n;j++){
			while(cnt[a[j]]){
				cnt[st[top]]--;
				top--;
			}
			st[++top]=a[j];
			cnt[a[j]]++;
		}
		for(int j=1;j<=m;j++){
			ans[j]+=cnt[j];
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
