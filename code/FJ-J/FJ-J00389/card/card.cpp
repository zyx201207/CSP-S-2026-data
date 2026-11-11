#include <bits/stdc++.h>
using namespace std;
int n,m,t,top;
int a[500005];
int b[300005];
int st[500005];
bool f(int x){
	for(int i=1;i<t;i++){
		if(x==st[i]){
			top=i;
			return 0;
		}
	}
	return 1;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	t=0;
	for(int j=1;j<=n;j++){
		for(int i=1;i<=t;i++){
			st[i]=0;
		}
		for(int i=j;i<=n;i++){
		if(f(a[i])==0){
			t=top;
		}
		else{
			t++;
			st[t]=a[i];
		}	
	}
	for(int i=1;i<=t;i++){
		b[st[i]]++;
	}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
} 
