#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=505;
ll n,m,a[N],b[N];
queue<int> q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=500&&m<=200){
		ll cnt[N]={0};
		for(int i=1;i<=n;i++){
			memset(b,0,sizeof(b));
			for(int k=q.size();k>=1;k--) q.pop();
			for(int k=i;k<=n;k++) q.push(a[k]);
			for(int k=q.size();k>=1;k--){b[k]=q.top();q.pop();}
			for(int k=i;k<=n;k++) q.push(a[k]);
			for(int j=i;j<=n;j++){
				for(int k=q.size();k>=1;k--){
					if(b[k]==a[j]) while(k--) q.pop();
				}
			}
			for(int k=i;k<=n;k++){b[k]=q.top();q.pop();}
			for(int j=1;j<=m;j++){
				for(int k=q.size();k>=1;k--){
					if(b[k]==j){cnt[j]++;break;}
				}
			}
		}
		for(int i=1;i<=m;i++){
			cout<<cnt[m]<<" ";
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*created by luve on 2026/10/31 11:27 0pts(?*/
