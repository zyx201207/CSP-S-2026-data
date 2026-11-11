#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010],b[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int c=i;
		b[a[i]]++;
		for(int k=c+1;k<=n;k++){
			b[a[k]]++;
			if(a[c]==a[k]){
				for(int d=i;d<k;d++){
					b[a[d]]--;
				}
				c=k;
			}
		}	
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<' ';
	}
	cout<<endl;
	return 0;
}
