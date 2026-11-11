#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m;
int a[N],c[N];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		c[i]=a[i];
	}
	sort(c+1,c+n+1);
	int sum=0;
	for(int i=1;i<=n;++i){
		if(a[i]!=c[i]){
			sum=1;
			continue;
		}
	}
	if(sum==0){
		for(int i=1;i<=n;++i){
			for(int j=i;j<=n;++j){
				if(a[i]==a[j]){
					cout<<max(i,j)<<" ";
				}
			}
		}
	}
	return 0;
}
