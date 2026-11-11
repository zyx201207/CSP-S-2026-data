#include<bits/stdc++.h>
using namespace std;
int n,m;
char a[300005];
int cnt[300005];
bool f[300005];
string st;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			f[j]=0;
		}
		st.clear();
		st+=a[i];
		for(int j=i+1;j<=n;j++){
			if(st.find(a[j])){
				for(int k=0;k<st.size();k++){
					st[k]='0';
					if(st[k]==a[j]){
						break;
					}
				}
			}
			st+=a[j];
		}
		for(int j=1;j<=n;j++){
			if(st.find(a[j])&&!f[a[j]-'0']){
				cnt[a[j]-'0']++;
				f[a[j]-'0']=1;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}
