#include<bits/stdc++.h>
using namespace std;
int a[100010];
int b[100010];
int main{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	int m1[100010];
	for(int i=0;i<m;i++){
		m1[i]=i+1;
    }	
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]]++;
		if(b[a[i]]>=2){
			cin>>a[i];
		}
	}
}
