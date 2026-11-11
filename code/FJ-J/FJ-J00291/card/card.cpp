#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,a[N],b[N],s[N],top;
int check(int x,int y){
	for(int i=1;i<=x;i++){
		if(s[i]==y)return i;
	}
	return 0;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		top=0;
		for(int j=i;j<=n;j++){
			int k=check(top,a[j]);
			if(k!=0)top=k-1;
			s[++top]=a[j];
		}
		for(int j=1;j<=top;j++){
			b[s[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}

