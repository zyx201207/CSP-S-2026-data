#include <bits/stdc++.h>
using namespace std;
int a[212345];
int ans[212345];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int k=1;k<=n;k++){
		vector<int> cnt(212345),table(n+10);
		int len=0;
		for(int i=k;i<=n;i++){
			if(cnt[a[i]]==0){
				cnt[a[i]]++;
				len++;
				table[len]=a[i];
			}else{
				int st=1;
				for(int j=1;j<=len;j++){
					if(table[j]==a[i]){
						st=j;
						break;
					}
				}
				
				for(int j=st;j<=len;j++){
					cnt[table[j]]--;
				}
				cout<<st<<endl;
				len=st;
				table[len]=a[i];
			}
			
		}
		for(int j=1;j<=len;j++){
			ans[table[j]]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	cout<<endl;
	return 0;
}
