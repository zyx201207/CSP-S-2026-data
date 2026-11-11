#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,mx,t,ans;
int x[N];   // 输入数据 
bool v[N];   // 标记 
string a[N];   // 2进制编码 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>x[i];
		int u=x[i];
		a[i]="";
		t=0;
		while(u>0){
			a[i]=to_string(u&1)+a[i];
			u>>=1;
			t++;
		}
		mx=max(t,mx);
	}
	for (int i=1;i<=n;i++){
		while(a[i].size()<mx){
			a[i]='0'+a[i];
		}
	}
	ans=n;
	for (int i=0;i<mx;i++){
		int s=0;
		for (int k=1;k<=n;k++){
			if (!v[k] && a[k][i]=='1'){
				s++;
			}
		}
		if (s<m) continue;
		if (s>=m){
			for (int k=1;k<=n;k++){
				if (!v[k] && a[k][i]=='0'){
					v[k]=1;
				}
			}
		}
	}
	int cnt=INT_MAX;
	for (int k=1;k<=n;k++){
		if (!v[k]) cnt&=x[k];
	}
	cout<<cnt;
	return 0;
}
