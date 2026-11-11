#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],s[300005],cnt[300005];
bool f[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int len=1;
		for(int j=1;j<=m;j++){
			s[j]=0;
			f[j]=0;
		}
		for(int j=i;j<=n;j++){
			if(f[a[j]]==0){
				s[len]=a[j];
				len++;
				f[a[j]]=1;
			}else{
				while(s[len]!=a[j]){
					s[len]=0;
					len--;
				}
				len++;
			}
		}
		for(int j=1;j<len;j++){
			cnt[s[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}/*
10 3
3 1 2 1 3 2 3 1 2 1
*/
