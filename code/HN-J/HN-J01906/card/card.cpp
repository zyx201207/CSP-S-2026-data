#include<bits/stdc++.h>
using namespace std;
const int N = 5*1e5 + 101;
int n,m,x,c,p,ans,a[N];
bool f;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		ans = 0;
		cin >> x;//4
		f = 0;
		for(int j=1;j<=c;j++){
			if(x==a[j]){//ур╣╫ак 
				f = 1;
				p = j;
				break;
			}
		}
		if(f==1){
			c -= c+1-p;
		}
		a[++c] = x;
		for(int i=1;i<=c;i++)
			if(a[i]==m)
				ans++;
		cout << ans << " ";
	}
	return 0;
}
