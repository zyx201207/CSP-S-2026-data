#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],ans[300010],anss[300010],aa[500010];
string s;
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++){
		if(anss[a[i]]==0){
			anss[a[i]]=1;
			aa[i]=a[i];
		}
	}
	for(int x=1;x<=n;x++){
		for(int i=x-1;i<n;i++){
			s+=a[i];
			int len=s.size();
			for(int j=0;j<len;j++){
				if(s[j]-'0'==a[i]){
					for(int k=j;k<len;k++){
						s[k]=' ';
					}
					s[j]=a[i];
					break;
				}
			}
		}
		for(int i=0;i<n;i++){
			int len=s.size();
			for(int j=0;j<len;j++){
				if(s[j]-'0'==aa[i]){
					ans[aa[i]]++;
					break;
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
} 
