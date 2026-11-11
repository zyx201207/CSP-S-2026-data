#include <bits/stdc++.h>
using namespace std;
const int mx=5E5+10;
int a[mx],b[mx],n,m,ans[mx],c[mx];
map<int,int> M;
void pp(){
    for(int i=1;i<=n;i++) cout<<b[i]<<' ';
    cout<<'\n';
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=m;i++) ans[i]=0;
	for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=M[a[i]];
        M[a[i]]=i;
	}
//	pp();
	for(int i=1;i<=n;i++){
        if(a[i]!=a[n]){
            for(int j=i;j<=n;j++){
                c[j]=1;
                if(c[b[j]]==1)
                    for(int k=b[j];k<j;k++) c[k]=0;
            }
            for(int j=1;j<=n;j++){
                if(c[j]==1) ans[a[j]]++;
                c[j]=0;
            }
        }
        else{
            ans[a[n]]++;
        }
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}
