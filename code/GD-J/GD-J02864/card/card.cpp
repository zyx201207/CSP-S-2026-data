#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m;
int a[N],b[N],cnt[N];
int pos[300005];
bool check(){
	for(int i=2;i<=n;i++){
		if(a[i]<a[i-1]) return false;
	}
	return true;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	int maxn=-1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	if(check()){
		for(int i=1;i<=n;i++){
			cnt[a[i]]=i;
		}
		for(int i=1;i<=maxn;i++){
			if(cnt[i]) cout<<cnt[i]<<" ";
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			pos[b[j]]=0;
		}
		for(int j=i;j<=n;j++){
			b[j]=a[j];
		}
		for(int j=i;j<=n;j++){
			if(pos[b[j]]){
				int l=pos[b[j]],r=j-1;
				for(int k=l;k<=r;k++){
					b[j]=0;
				}
			}
			pos[b[j]]=j;
		}
		for(int j=i;j<=n;j++){
			if(b[j]) cnt[b[j]]++;
		}
	}
	for(int i=1;i<=maxn;i++){
		if(cnt[i]) cout<<cnt[i]<<" ";
	}
	return 0;
} 
