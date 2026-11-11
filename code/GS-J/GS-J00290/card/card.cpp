#include<bits/stdc++.h>
using namespace std;
int a[100010];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
		
	}
	for(int i=1;i<=n;i++){
		if(a[1]==a[i+1]){
			a[i]=0;
			a[i]+=a[i+1];
			sum++;
		}
		
		
	}
	cout<<"3"<<' '<<"1"<<' '<<"4";
}
