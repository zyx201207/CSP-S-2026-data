#include<bits/stdc++.h>
using namespace std;
long long a[500005],b[500005];
int main(){
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(b[i]){
			for(int j=b[i]+1;j<i;j++){
				b[a[j]]--;
			}
			b[a[i]]=i;
			continue;
		}
		b[a[i]]=i;
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}

	return 0;
}
