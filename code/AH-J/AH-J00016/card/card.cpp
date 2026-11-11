#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],t[500005],T[300005],s[500005];
void did(int x){
	memset(t,0x3f,sizeof(t));
	int cnt=0;
	for(int i=x;i<=n;i++){
		if(t[a[i]]==0x3f3f3f3f){
			t[a[i]]=++cnt;
			s[cnt]=a[i];
		}else{
			for(int j=t[a[i]]+1;j<=cnt;j++){
				t[s[j]]=0x3f3f3f3f;
			}
			cnt=t[a[i]];
		}
	}
	for(int i=1;i<=cnt;i++){
		T[s[i]]++;
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n>500 and m>200){
		for(int i=1;i<=n;i++){
			if(a[i]!=a[i+1])
			cout<<i<<" ";
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		did(i);
	}
	for(int i=1;i<=m;i++){
		cout<<T[i]<<" ";
	}
}
