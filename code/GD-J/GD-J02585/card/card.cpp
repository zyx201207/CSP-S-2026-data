#include<bits/stdc++.h>
using namespace std;
const int K=5e5+91;
int a[K];
int n,m;
int st=0;
int cnt[K];
int ans[K];
int last[K];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n>500){
		for(int i=1;i<=n;i++){
			last[a[i]]=i;
		}
		for(int i=1;i<=m;i++){
			cout<<last[i]<<' ';
		}
		cout<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int cmp=0;
			for(int c=1;c<=st;c++){
				if(a[j]==cnt[c]){
					st=c-1;
					break;
				}
			}
			cnt[++st]=a[j];
		}
		for(int j=1;j<=st;j++){
			ans[cnt[j]]++;
		}
		st=0;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	
	
	return 0;
}
