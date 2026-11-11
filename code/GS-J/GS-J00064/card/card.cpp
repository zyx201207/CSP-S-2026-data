#include<bits/stdc++.h>
using namespace std;
int a[300010],ans[300010],s[500010];
	int n,m;
void an(){
	for(int i=1;i<=m;i++)ans[i]=0;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int i=1;i<=n;i++){
		an();
		for(int j=i;j<=n;j++){
			if(ans[s[j]]==0){
				ans[s[j]]++;
			}
			else{
				for(int l=j-1;l>=1;l--){
					if(s[l]==s[j]){
						break;
					}
					ans[s[l]]=0;
				}
			}
		}
		for(int j=1;j<=m;j++){
			a[j]+=ans[j];
		}
	}
	for(int i=1;i<=m;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}
