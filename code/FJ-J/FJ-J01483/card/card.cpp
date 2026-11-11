#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500001],b[500001],c[300001];
int find(int x){
	for(int i=1;i<=n;i++){
		if(b[i]==x) return i;
	}
	return -1;
}
void f(int x){
	for(int i=x;i<=n;i++) b[i]=0;
	return ;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	int cnt;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cnt=1;
		for(int j=1;j<=n;j++) b[j]=0;
		for(int j=i;j<=n;j++){			
			if(find(a[j])==-1){
				b[cnt]=a[j];
				cnt++;
			}
			else{
				f(find(a[j])+1);
				cnt=find(a[j])+1;
			}
		}
		for(int i=1;i<=n;i++){
			c[b[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<' ';
	}
	return 0;
}
