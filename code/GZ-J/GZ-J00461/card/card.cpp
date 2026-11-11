//GZ-J00461 สตั้ศý ั๎ฯ่๎ฃ
#include<bits/stdc++.h>
using namespace std;
int n,m,x[500005],game[500005],q[500005],sum[300005],a,b;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>x[i];
	for(int k=1;k<=m;k++){
		for(int i=k;i<=n;i++){
			bool f=0;
			for(int j=1;j<i;j++){
				if(f==1) q[++b]=game[j],game[j]=0;
				if(x[i]==game[j]) f=1,q[++b]=game[j];
			}
			if(!f) game[++a]=x[i];
		}
		for(int i=1;i<=a;i++) sum[game[i]]++;
	}
	for(int i=1;i<=m;i++) cout<<sum[i]<<" ";
	return 0;
}
