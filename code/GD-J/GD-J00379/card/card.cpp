#include<bits/stdc++.h>

using namespace std;
const int N=5e5+7;
int n,m;
int a[N];
int s[N],top;
int cnt[N];
int d[N];
int lst[N];
int b[N],tot,len[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	bool flag=0;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<n;i++) if(a[i]>a[i+1]){
		flag=1;break;
	}
	if(!flag){
		for(int i=1;i<=n;i++) lst[a[i]]=i;
		for(int i=1;i<=m;i++) cout<<lst[i]<<(i==m?"\n":" ");
		return 0;
	}
	for(int i=1,j=1;i<=n;i++,j++)
		if(a[i]!=a[i+1]){
			b[++tot]=a[i];
			len[tot]=j;
			j=0;
		}
	if(tot<=10000){
		for(int i=1;i<=tot;i++){
			top=0;
			for(int j=i;j<=tot;j++){
				if(cnt[b[j]]>0){
					do{
						cnt[s[top]]--;
					}while(s[top--]!=b[j]);
				}
				s[++top]=b[j];
				cnt[b[j]]++;
			}
			for(int j=1;j<=top;j++) cnt[s[j]]--,d[s[j]]+=len[i];
		}
		for(int i=1;i<=m;i++) cout<<d[i]<<(i==m?"\n":" ");
		return 0;
	}
	if(n<=10000){
		for(int i=1;i<=n;i++){
			top=0;
			for(int j=i;j<=n;j++){
				if(cnt[a[j]]){
					do{
						cnt[s[top]]--;
					}while(s[top--]!=a[j]);
				}
				s[++top]=a[j];
				cnt[a[j]]++;
			}
			for(int j=1;j<=top;j++) d[s[j]]++,cnt[s[j]]--;
		}for(int i=1;i<=m;i++) cout<<d[i]<<(i==m?"\n":" ");
		return 0;
	}
	return 0;
}
