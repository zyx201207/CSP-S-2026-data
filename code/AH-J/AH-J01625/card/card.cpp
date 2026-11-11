#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[300005],c[500005],ans[300005],d[500005],f;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie();cout.tie();
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++){
		if(a[i]!=b[i]){
			f=1;
		}
	}
	if(!f){
		for(int i=1;i<=n;i++){
			if(a[i]!=a[i+1]){
				ans[a[i]]=i;
			}
		}
		for(int i=1;i<=m;i++){
			cout<<ans[i]<<" ";
		}
	}
	else{
		for(int i=1;i<=n;i++){
			memset(b,0,sizeof(b));
			memset(c,0,sizeof(c));
			int l=i;
			for(int j=i;j<=n;j++){
				if(b[a[j]]>=l){
//					cout<<l<<" "<<b[a[j]]<<"\n";
					c[b[a[j]]]--;
					c[j]++;
					b[a[j]]=j;
					l=j;
				}
				else b[a[j]]=j;
			}
			for(int j=1;j<=n;j++){
				c[j]=c[j-1]-c[j];
			}
//			for(int j=1;j<=n;j++){
//				cout<<c[j]<<" ";
//			}cout<<"\n";
			for(int j=i;j<=n;j++){
				ans[a[j]]+=1-c[j];
			}
		}
		for(int i=1;i<=m;i++){
			cout<<ans[i]<<" ";
		}
	}
	return 0;
}
