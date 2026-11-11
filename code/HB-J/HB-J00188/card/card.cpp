#include<bits/stdc++.h>
using namespace std;
int n,m,a[5005],s[3005],q[5005];bool b[3005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(q,0,sizeof(q));memset(b,0,sizeof(b));
		int t=0;
		for(int j=i;j<=n;j++){
			if(b[a[j]]){while(q[t]!=a[j]){b[q[t]]=0;t--;}}
			else {q[++t]=a[j];b[a[j]]=1;}
		}
		for(int i=1;i<=t;i++){s[q[i]]++;}
	}
	for(int i=1;i<=m;i++)cout<<s[i]<<" ";
	return 0;
}
