#include<bits/stdc++.h>
using namespace std;
int n,m,num[1000001],cnt[100001],tong[100001];
queue<int>q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>num[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			tong[num[j]]++;
			if(tong[num[j]]==2){
				while(!q.empty()){
					tong[q.front()]--;
					q.pop();}
			}
			q.push(num[j]);
		}
		int rem[1000001],g;
		while(!q.empty()){
			cnt[q.front()]++;	
			rem[g]=q.front();
			g++;
			q.pop();}
		while(g!=0){
			q.push(rem[g]);
			g--;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
