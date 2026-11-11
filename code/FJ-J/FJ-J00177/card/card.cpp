#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
long long n,m,a[N];
long long t[N],p[N],ans[N],cnt,p1[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cnt=0;
		for(int j=1;j<=m;j++){
			t[j]=0;
		}
		for(int j=i;j<=n;j++){
			if(t[a[j]]==0){
				cnt++;
				p[a[j]]=cnt;
				p1[cnt]=a[j];
				t[a[j]]=1;
			}
			else{
				for(int k=p[a[j]]+1;k<=cnt;k++){
					t[p1[k]]=0;
					p[p1[k]]=0;
				}
				cnt=p[a[j]];
			}
		}
		for(int k=1;k<=m;k++){
			if(t[k]==1){
				ans[k]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
