#include<bits/stdc++.h>
using namespace std;
const int N=5e5+1;
int a[N],b[N],c[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,m,ans=0;
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=1;i<=n;i++){
		b[1]=a[i];
		int cnt=1;
		for(int j=i+1;j<=n;j++){
			bool f=0;
			for(int k=1;k<=cnt;k++)
				if(b[k]==a[j])
					cnt=k,f=1;
			if(!f) b[++cnt]=a[j];
		}
		for(int k=1;k<=m;k++)
			for(int j=1;j<=cnt;j++)
				if(b[j]==k)
					c[k]++;
	}
	for(int i=1;i<=m;i++) cout << c[i] << ' ';
	return 0;
} 
