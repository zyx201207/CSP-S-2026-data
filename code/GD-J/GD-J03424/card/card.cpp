#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[200005],top=1,len,cnt[300005];
void game(long long x){
	memset(b,0,sizeof(b));
	int len=x;
	for (int i=len;i<=n;i++){
		int y=a[i];
		for (int j=len;j<top;j++){
			if (b[j]==y) top=j;
		}
		b[top++]=y;
	}
	for (int i=1;i<top;i++){
		cnt[b[i]]++;
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","l",stdout);
	cin >>n>>m;
	for (int i=1;i<=n;i++){
		cin >>a[i];
	}
	for (int i=1;i<=n;i++){
		game(i);
	}
	for (int i=1;i<=m;i++) cout <<cnt[i]<<" ";
	return 0;
}
