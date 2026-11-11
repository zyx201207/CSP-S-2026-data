#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[10000];
int ans=0;
int cnt=0;
int b=1;
int main(){
	freopen(" crystal.in","r",stdin);
	freopen(" crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int i=1;i<=m;++i){
		a[1]++;
		ans++;
		if(a[1]==a[2]){
			break;
		}
		
	}
    for(int i=1;i<=1;++i){
    	a[1]+=(m-ans)/2;
    	a[2]+=(m-ans)/2;
	}

	for(int i=1;i<=n;++i){
		
		if(a[b]==a[b+1]){
			cnt++;
		}
		b++;
	}
	cout<<cnt+1;
	return 0;
}
