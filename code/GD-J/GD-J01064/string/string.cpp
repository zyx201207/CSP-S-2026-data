#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],l[500005],k[500005]; 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int x=1;x<=n;x++){
		for(int i=x;i<=n;i++){
			if(l[i]==0)l[i]=a[i];
			else {
				for(int j=i;;j--){
					if(l[j]=a[i])break;
					l[j]=0;
				}
			}
		}
		for(int i=x;i<=n;i++){
			k[l[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<k[i];
	}
	return 0;
}

