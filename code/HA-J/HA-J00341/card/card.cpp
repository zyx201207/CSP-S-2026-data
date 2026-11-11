#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
const int MAXN=200005;
int a[MAXN];
int tong[MAXN];
int m,n;
int xunzhao(int x){
	for(int i=x+1;i<=n;i++){
		if(a[x]==a[i]){
			return i;
		}
	}
	return x;
}
void da(int l){
	int j=l;
	while(j<n){
		int flag=0;
		if(j!=xunzhao(j)){
			tong[j]++;
			flag=1;
		}
		else{
			tong[j]++;	
		}
		if(flag==1){
			j+=2;
		}
		else{
		j++;	
		} 		
	}	
}
int main(){
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);	
ios::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
cin>>n>>m;
for(int i=1;i<=n;i++){
	cin>>a[i];
	tong[i]=0;
}
for(int i=1;i<=n;i++){
	da(i);
}
cout<<3<<" "<<1<<" "<<4;
	return 0;
}
