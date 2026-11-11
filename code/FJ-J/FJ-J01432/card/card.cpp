#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+10,M = 3e5+10; 
int n,m,a[N],cnt[M],a1[N];
int check(int x){
	for(int i = 1;i<=n;i++){
		if(a[i]==x)return i;
	}
	return 0;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i = 1;i<=n;i++)cin>>a[i];
	for(int i = 0;i<n;i++){
		for(int j = 1;j<=n;j++)a1[j]=a[j];
		int s = 1;
		for(int j = i+1;j<=n;j++){
			if(check(a[j])){
				for(int k = check(a[j]);k<=n;k++){
					a1[k] = 0;
				}
			}else{
				a1[s] = a[j];
				s++;
			}
		}
		for(int j = 1;j<=m;j++){
			for(int k = 1;k<=s;k++){
				if(a1[k] == m)cnt[m]++;
			}
		}
	}
	for(int i = 1;i<=m;i++)cout<<cnt[i]<<' ';
	return 0;
}

