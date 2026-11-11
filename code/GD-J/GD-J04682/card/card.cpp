#include<bits/stdc++.h>
using namespace std;
const int N = 5E5+5;
int a[N],b[N],ans[N];
int st[N],cnt;
int n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			b[j] = 0;
		}
		cnt = 0;
		for(int j = i;j <= n;j++){
			if(b[a[j]] != 0){
				while(st[cnt] != a[j]){
					b[st[cnt]] = 0;
					cnt--;
				}
				b[st[cnt]] = 0;
				cnt--;
			}
			st[++cnt] = a[j];
			b[a[j]] = cnt;
		}
		for(int j = 1;j <= m;j++){
			if(b[j] != 0){
				ans[j] += 1;
			}
		}
	}
	for(int i = 1;i <= m;i++){
		cout<<ans[i]<<" ";
	}
}
