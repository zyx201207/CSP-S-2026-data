#include<bits/stdc++.h>
using namespace std;
int a[500010];
int t[300010];
int s[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		t[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		int l=i;
		while(l<=n){
			s[a[l]]++;
			int ll=l;
			l=t[a[ll]]+1;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<s[i]<<" ";
	}
}
