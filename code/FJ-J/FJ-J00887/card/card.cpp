#include<bits/stdc++.h>
using namespace std;
//I Love You CCF !
const int N=5e5+500;
const int M=3e5+500;
int n,m;
int a[N];
int cnt[M];
int ve[M];
int p=1;
int b[M];
void cl(){
	for(int i=1;i<=n;i++){
		ve[i]=b[i]=0;
	}
	p=1;
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cl();
		for(int j=i;j<=n;j++){
			ve[p]=a[j];
			if(b[a[j]]==0){
				b[a[j]]=p;
				p++;
			}else{
				p=b[a[j]]+1;
			} 
		}
		for(int j=1;j<p;j++){
			cnt[ve[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		if(cnt[i]>n)cnt[i]=n;
		cout<<cnt[i]<<" ";
	}
	return 0;
}
