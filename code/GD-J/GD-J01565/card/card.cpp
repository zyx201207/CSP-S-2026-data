#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],t[300005],b[300005];
bool tt,c[300005];
stack<int> st;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i-1]>a[i]){
			tt=true;
		}
		t[a[i]]++;
	}
	if(!tt){
		for(int i=1;i<=m;i++){
			t[i]+=t[i-1];
			cout<<t[i]<<' ';
		}
	}
	else if(m==1){
		cout<<n;
	}
	else{
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				
			}
		}
	}
	return 0;
} 
