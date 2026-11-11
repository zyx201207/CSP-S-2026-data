#include<bits/stdc++.h>
using namespace std;
const int MAXN=500005;
int n,m,a[MAXN],cd[MAXN],cnt=1,mark[MAXN],ans[MAXN];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		memset(cd,0,sizeof(cd));
		memset(mark,0,sizeof(mark));
		cnt=1;
		for(int j=i;j<=n;j++){
			if(mark[a[j]]==0){cd[cnt]=a[j];mark[a[j]]=cnt;cnt++;}
			else{
				cnt=mark[a[j]];
				cd[cnt]=a[j];
				cnt++;
			}
//			cout<<cnt<<endl;
		}
		for(int j=1;j<cnt;j++){
			ans[cd[j]]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	cout<<endl;
	return 0;
}
