#include<bits/stdc++.h>
using namespace std;
char a[1000001000],c;
long long  n,ans,data,sumlon,sumll,tell=1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>data>>c;
		sumlon+=data;
		while(data--){
			a[tell++]=c;
		}
	}sumll=sumlon;
	sumlon=ceil(sumlon/2);
	if(sumlon%2!=0){
		for(int i=1;i<sumlon;i++){
			if(a[i]!=a[sumll-i]){
				ans++;
			}
		}
	}else{
		for(int i=1;i<=sumlon;i++){
			if(a[i]!=a[sumll-i]){
				ans++;
			}
		}
	}cout<<ans;
	return 0;
}
