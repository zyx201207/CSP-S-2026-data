#include<bits/stdc++.h>
using namespace std;
long long m,n,ih[200005],c[200005],j1[200005],ans,rt;
int o(int q){
	for(int i=1;i<=n;i++){
		if(c[i]==q){
			return i;
		}
	}
	return -1;
}
int ou(int q){
	int p;
	for(int i=q-1;i<=n;i++){
		c[i]=0;
		p++;
	}
	return p;
}
int main(){
	freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>ih[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			c[rt]=ih[j];
			if(o(ih[j])){
				rt-=ou(o(ih[j]));
			}
			rt++;
		}
		for(int i=1;i<=rt;i++){
			if(j1[c[i]]==0){
				j1[c[i]]=1;
				ans++;
			}
		}
		for(int i=1;i<=n;i++){
			j1[i]=0;
		}
	}
	cout<<ans;
    return 0;
}
