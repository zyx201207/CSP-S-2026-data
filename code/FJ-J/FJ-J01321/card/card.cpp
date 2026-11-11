#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int arr[1000000];
int num[1000000];
int t[1000000];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>arr[i];
		t[arr[i]]=i;
	}

	for(int i=1;i<=n;++i){
		int x=i;
		while(x<=n){
		num[arr[x]]++;
		if(t[arr[x]]!=x){
			x=t[arr[x]]+1;
		}else{
			x++;
		}
		}
		
	}
	for(int i=1;i<=m;++i){
		cout<<num[i]<<" ";
	}
	return  0;
}
