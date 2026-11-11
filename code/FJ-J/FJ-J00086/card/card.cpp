#include<bits/stdc++.h>
using namespace std;
int a[500010],v[300010],ans[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	string s;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			s+=a[j];
			int l=s.size();
			if(v[int(s[l])]==1){
				for(int k=l-1;k>=1;k--){
					if(s[k]==s[l]){
						break;
					}v[int(s[k])]=0;
				}
			}v[int(s[l])]=1;
		}
		for(int j=1;j<=m;j++){
			if(v[j]==1){
				ans[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
