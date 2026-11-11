#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],s[500010]={0},cnt[300010]={0},ms=400000;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(s[a[j]]){
				for(int k=s[a[j]];k<=n;k++){
					s[k]=0;
				}
			}
			s[a[j]]=j;
		}
		for(int j=i;j<=n;j++){
			if(s[a[j]]>0&&s[a[j]]<ms){
				ms=s[a[j]];
			}
		}
		for(int j=ms;j<=n;j++){
			cnt[a[j]]++;
		}
		for(int j=1;j<=n;j++){
			s[j]=0;
		}
		ms=400000;
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<' ';
	}
	return 0;
}
