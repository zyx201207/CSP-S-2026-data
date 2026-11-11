#include <bits/stdc++.h>
using namespace std;

int a[10000];
int er[10000];
int cnt[10000];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		int x=a[i];
		while(x/2>0){
			cnt[i]+=1;
		}
		whie(a[i]/2>0){
			er[i]+=a[i]%2;
		}
	}
	return 0;
}
