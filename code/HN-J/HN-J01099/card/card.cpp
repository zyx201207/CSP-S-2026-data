#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200005],c[200005],f[200005],b[200005],lst[200005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	int flag=0;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(flag==0&&i!=1) continue;
		if(a[i]>=a[i-1]) flag=1;
		else flag=0;
	}
	if(flag){
		for(int i=1;i<=n;i++) c[a[i]]=i;
		for(int i=1;i<=m;i++) cout << c[i] << ' '; 
	}
	else{
		for(int l=1;l<=n;l++){
			for(int i=1;i<=n;i++) lst[a[i]]=f[a[i]]=0;
			for(int i=l;i<=n;i++){
				if(lst[a[i]]>0){
					for(int j=lst[a[i]]+1;j<i;j++){
						f[a[j]]=0;
						lst[a[j]]=0;
					}
					lst[a[i]]=i;
					f[a[i]]=1;
				}
				else{
					lst[a[i]]=i;
					f[a[i]]=1;
				}
			}
			for(int i=1;i<=m;i++) c[i]+=f[i];
		}
		for(int i=1;i<=m;i++) cout << c[i] << ' ';
	}
	return 0;
}
/*
 
10:52 xie wan
100+100+50+52
Trick||Treat!!! 
while(1) RP++; 
*/

