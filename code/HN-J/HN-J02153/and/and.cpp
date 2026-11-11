#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[200005],b[200005];
int main(){
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==2){
		int l=1;
		int maxn=a[l]&a[2];
		for(int i=2;i<=n;i++){
			l++;
			if(maxn<=a[l]&a[i+1]){
				maxn=a[l]&a[i+1];
				
			}
		
		}
		cout<<maxn;
		return 0;
	}
}
