#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],da[200005];
bool f[200005],fl[200005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=n;i>=1;i--){
        da[a[i]]=max(da[a[i]],i);
        if(f[a[i]]){
			for(int i=1;i<=m;i++){
				fl[i]=false;
			}
            for(int j=i+1;a[j]!=a[i];j++){
                if(!fl[a[j]]){
					da[a[j]]--;
					fl[a[j]]=true;
				}
            }
        }
        f[a[i]]=true;
    }
    for(int i=1;i<=m;i++){
        cout<<da[i]<<' ';
    }
    return 0;
}
