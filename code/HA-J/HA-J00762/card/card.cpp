#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],mk[500010],k[500010];
deque<int>b;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=0;i<n;i++){
		for(int j=i+1;j<=n;j++){
			if(!mk[a[j]]){
				b.push_back(a[j]);
				mk[a[j]]=1;
			}else{
				while(b.back()!=a[j]){
					mk[b.back()]=0;
					b.pop_back();
				}
			}
		}while(b.size()){
			k[b.back()]++;
			b.pop_back();
		}memset(mk,0,sizeof(mk));
	}for(int i=1;i<=m;i++){
		cout<<k[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
