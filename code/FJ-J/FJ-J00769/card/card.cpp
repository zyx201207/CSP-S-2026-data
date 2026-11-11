#include<bits/stdc++.h>
using namespace std;
int sum;
int n,a[500001],m,b[500001],d[500001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	b[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;){
			d[a[j]]++;
			j=b[a[j]]+1;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<d[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
