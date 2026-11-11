#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010],t[100010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long i,j,k;
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	for(i=1;i<=n;i++){
		long long b[200010]={0},c=1;
		map<long long,long long> mp;
		for(j=i;j<=n;j++){
			if(mp[a[j]]==0){
				b[c]=a[j];
				c++;
				mp[a[j]]++;
			}else{
				for(k=i;k<=c;k++){
					if(b[k]==a[j]){
						c=k;
						break;
					}
				}
			}
		}
		for(i=1;i<=c;i++){
			t[b[i]]++;
		}
	}
	for(i=1;i<=m;i++){
		cout<<t[i]<<" ";
	}
	return 0;
}
