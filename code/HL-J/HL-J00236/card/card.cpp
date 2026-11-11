#include <bits/stdc++.h>
using namespace std;
const int N = 200005,M = 100005;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int a[N],m,n,t[N],c[M];
    memset(t,0,sizeof(t));
    memset(c,0,sizeof(c));
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
    	cin >> a[i];
	}
	for(int p = 1;p <= n;p++){//n times games
		for(int i = p;i <= n;i++){//fapai from p-n
			if(t[a[i]] != 0){//chongfu
				for(int j = i-1;j > t[a[i]];j--){
					t[a[j]] = 0;
				}
			}
			t[a[i]] = i;
		}
		for(int i = 1;i <= m;i++){
			if(t[i] != 0){
				c[i]++;
				//cout << 1 << endl;
			}
		}
		//cout << endl;
		memset(t,0,sizeof(t));
	}
	for(int i = 1;i <= m;i++){
		cout << c[i] << " ";
	}
    return 0;
}
