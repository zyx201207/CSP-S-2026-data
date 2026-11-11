#include<bits/stdc++.h>
#define int long long
using namespace std;
char a[211111];
int n,b[211111],nu;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>b[i]>>a[i];
	}
	int t=1,w=n;
	while(t<w){
		if(b[t]>b[w]){
			b[t]-=b[w];
			if(a[t]==a[w]){
				w--;
			}else{
				nu+=b[w];
				w--;
			}
		}else if(b[t]==b[w]){
			if(a[t]==a[w]){
				w--;
				t++;
			}else{
				nu+=b[w];
				w--;
				t++;
			}
		}else{
			b[w]-=b[t];
			if(a[t]==a[w]){
				t++;
			}else{
				nu+=b[t];
				t++;
			}
		}
	}
	cout<<nu;
	return 0;
}
