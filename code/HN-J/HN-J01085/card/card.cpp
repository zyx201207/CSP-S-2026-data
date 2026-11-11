#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,sum;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	int a[n+1]={0},b[m+1]={0};
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<n;i++){
		bool c[m+1]={false},d[m+1]={true};
		b[a[i]]++;
		for(int j=i+1;j<=n;j++){
			if(a[i]==a[j]){
				if(!c[i]){
					b[a[i]]++;
					c[i]=true;
				}
				for(int k=i;k<=j;k++){
					d[k]=false;
				}
			}
		}
		if(!c[a[i]]&&!d[a[i]]) b[a[i]]++;
	}
	for(int i=1;i<n;i++){
		cout<<b[i]-1<<" ";
	}
	return 0;
} 
