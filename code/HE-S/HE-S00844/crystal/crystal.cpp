#include <bits/stdc++.h>
using namespace std;
unsigned long long m;
const int N=5e5+10;
int n,engg[N],k=0,s=0,ans=0;
int compa(int u){
	int y=0;
	for(int j=1;j<n;j++){
		y=y+engg[n-1]-engg[n-1-j];
	}
	if(m>=y){
		s=n;
		return 0;
	}
	for(int j=1;j<u;j++){
		k=k+engg[u-1]-engg[u-1-j];
		if(k>m){
			k=0;
			s=j;
			return 0;
		}
		if(k==m){
			k=0;
			s=j+1;
			return 0;
		}
	}
	return 0;
}
	

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
    for(int i=0;i<n;i++)
    	cin >> engg[i];
    sort(engg,engg+n);
    for(int i=n;i>0;i--){
    	compa(i);
    	ans=max(ans,s);
    	s=0;
	}
	cout << ans;
	return 0;
}
