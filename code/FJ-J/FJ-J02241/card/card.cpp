#include<bits/stdc++.h>
using namespace std;
inline void read(int &x){
	x=0;
	char c=getchar();
	while(c>='0'&&c<='9'){
		x=x*10+(c-'0');
		c=getchar();
	}
	return;
}
int n,m,a[500005],cnt[300005];
bool chk[300005],chk2[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	read(n);
	read(m);
	for(int i=1;i<=n;i++){
		read(a[i]);
	}
	for(int i=1;i<=n;i++){
		memset(chk,false,sizeof(chk));
		memset(chk2,false,sizeof(chk2));
		for(int j=i;j<=n;j++){
			if(chk[a[j]]){
				int k=j-1;
				while(a[k]!=a[j]){
					if(chk2[k]){
						chk2[k]=false;
						chk[a[k]]=false;
						cnt[a[k]]--;
					}
					k--;
				}
				continue;
			}
			chk2[j]=true;
			chk[a[j]]=true;
			cnt[a[j]]++;
		}
//		for(int j=1;j<=m;j++){
//			cout<<cnt[j]<<" ";
//		}
//		cout<<endl;
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}