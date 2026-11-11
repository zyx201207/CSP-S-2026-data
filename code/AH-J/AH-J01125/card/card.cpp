#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,m,a[500005],t[300005],b[500005],p,cnt[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		p=0;
		memset(b,0,sizeof(b));
		memset(t,0,sizeof(t));
		for(int j=i;j<=n;j++){
			if(t[a[j]]>0){
				int pos;
				for(int i=1;i<=p;i++){
					if(b[i]==a[j]){
						pos=i;
					}
				}
				for(int i=pos;i<=p;i++){
					t[b[i]]--;
					b[i]=0;
				}
				p=pos-1;
				b[++p]=a[j];
				t[a[j]]++;
			}else{
				b[++p]=a[j];
				t[b[p]]++;
			}
		}
		for(int i=1;i<=m;i++){
			if(t[i]>0){
				cnt[i]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}
