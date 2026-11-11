#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,a[N];
int s[N],b[N],bs[N],bx=1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(bs,0,sizeof(bs));
		memset(b,0,sizeof(b));
		bx=1;
		for(int j=i;j<=n;j++){
			b[bx]=a[j];
			bs[a[j]]++;
			if(bs[a[j]]>1){
				b[bx]=0;
				bs[a[j]]--;
				for(int k=bx-1;k>=1;k--){
					if(b[k]==a[j]){
						break;
					}else{
						bs[b[k]]--;
						b[k]=0;
						bx--;
					}
				}
			}else{
				bx++;
			}
		}
		for(int i=1;i<=m;i++){
			s[i]+=bs[i];
		}
	}
	for(int i=1;i<=m;i++){
		cout<<s[i]<<' ';
	}
	return 0;
}
