#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int n,m,a[10005],c[10005],c1[10005];
int top=1,topc=1,topc1=1;
void game1(){
	int t=c[topc];
	topc--;
	for(int j=1;j<=top;j++){
		if(a[j]==t){
			for(int k=j;k<=top;k++)c1[topc1++]=a[k];
			top=j-1;
		}
	}
	top++;
	a[top]=t;
}
void game2(){
	int t=c1[topc1];
	topc1--;
	for(int j=1;j<=top;j++){
		if(a[j]==t){
			for(int k=j;k<=top;k++)c[topc++]=a[k];
			top=j-1;
		}
	}
	top++;
	a[top]=t;
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	cin>>a[1];
	for(int i=2;i<=n;i++){
		int t;
		cin>>t;
		for(int j=1;j<=top;j++){
			if(a[j]==t){
				for(int k=j;k<=top;k++)c[topc++]=a[k];
				top=j-1;
			}
		}
		top++;
		a[top]=t;
	}
	m--;
	while(m--){
		for(int i=1;i<=topc;i++){
			//for(int i=1;i<=top;i++)cout<<a[i]<<' ';
			game1();
			
			for(int j=1;j<=top;j++){
				c1[topc1++]=a[j];
			}
		}
		m--;
		if(m<=0){
			for(int i=1;i<=top;i++)cout<<a[i]<<' ';
			return 0;
		}
		for(int i=1;i<=topc1;i++){
			//for(int i=1;i<=top;i++)cout<<a[i]<<' ';
			game2();
			for(int j=1;j<=top;j++){
				c[topc++]=a[j];
			}
		}
	}
	for(int i=1;i<=top;i++)cout<<a[i]<<' ';
	return 0;
}

