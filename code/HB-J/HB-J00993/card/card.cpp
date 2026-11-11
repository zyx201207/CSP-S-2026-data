#include <bits/stdc++.h>
using namespace std;
const int N=2e5+3;
const int M=3e5+3;
long long n,m,l,len;
int ar[N];
int cnt[M];

bool find(int x,int r){
	for(int i=l;i<r;i++){
		if(ar[i]==x){
			return true;
		}
	}
	return false;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>ar[i];
	}
	for(int i=1;i<=n;i++){
		l=i;
		len=0;
		for(int j=l;j<=n;j++){
			if(find(ar[j],j)){
				l=j;
			}
		}
		for(int j=l;j<=n;j++){
			cnt[ar[j]]+=1;
		}
	}
	for(int j=1;j<=m;j++){
		cout<<cnt[j]<<" ";
	}
	return 0;
}
