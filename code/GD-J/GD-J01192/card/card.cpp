#include <iostream>
#include <cstdio>
#include <algorithm>

#define N 500005

using namespace std;

int n,m,a[N];
int s[N];
int la[N];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		la[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		int j=i;
		while(j<=n){
			s[a[j]]++;
			j=la[a[j]]+1;
		}
		s[a[j]]++;
	}
	for(int i=1;i<=m;i++) cout<<s[i]<<' ';
	return 0;
} 
