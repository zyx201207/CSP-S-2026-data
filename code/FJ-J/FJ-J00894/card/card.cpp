#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
const int M=3e5+10;
int n,m,cnt[M],a[N],b[N];
bool v[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(v[a[j]]==false){
				b[++ans]=a[j];
				v[a[j]]=true;
			}
			else{
				for(int k=ans;k>=1;k--){
					if(b[k]!=a[j]){
						v[b[k]]=false;
						ans--;
					}
					else{
						break;
					}
				}
			}
		}
		for(int j=1;j<=ans;j++){
			cnt[b[j]]++;
			v[b[j]]=false;
		}
		ans=0;
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}
