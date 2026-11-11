#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
const int M=3e5+5;
int n,m;
int a[N],l[M],ans[M];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);

	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		l[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(l[a[j]]!=0&&l[a[j]]!=j){
				j=l[a[j]];
				ans[a[j]]++;
			}else{
				ans[a[j]]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}

