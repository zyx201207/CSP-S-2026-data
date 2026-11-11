#include<bits/stdc++.h>
using namespace std;
int n;
long long g[200005],c,e;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>g[i]>>s[i];
		c+=g[i];
	}
	long long k=0;
	for(int i=1;i<=n;i++){
		k+=g[i];
		if(k>=c/2){
			k=i;
			break;
		}
	}
	int l=1,r=n;
	while(l<=r&&l<=k&&r>=k){
		if(s[l]!=s[r]){
			if(g[l]>g[r]){
				e+=g[r];
				g[l]-=g[r];
				r--;
			}else{
				e+=g[l];
				g[r]-=g[l];
				l++;
			}
		}else{
			if(g[l]>g[r]){
				g[l]-=g[r];
				r--;
			}else{
				g[r]-=g[l];
				l++;
			}
		}
	}
	cout<<e;
	return 0;
}
