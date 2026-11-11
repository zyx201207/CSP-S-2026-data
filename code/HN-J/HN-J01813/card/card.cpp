#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m,a[N],top;
map<long long,long long>mp1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		top=0;
		map<long long,long long>mp,b;
		for(int j=i;j<=n;j++){
			b[++top]=a[j];
			mp[a[j]]++;
			if(mp[a[j]]>=2){
				mp[b[top]]--;
				top--;
				while(top>0&&a[j]!=b[top]){
					mp[b[top]]--;
					top--;
				}
			}
		}
		for(int j=1;j<=top;j++){
			if(b[j]<=m){
				mp1[b[j]]++;
			}
		}
	}
	for(int j=1;j<=m;j++){
		cout<<mp1[j]<<" ";
	}
	return 0;
}

