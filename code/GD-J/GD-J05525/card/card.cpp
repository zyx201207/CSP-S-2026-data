#include<bits/stdc++.h>
using namespace std;
string s;
long long n,m,a[100000],d[1000000];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		vector<int> c(n+7,0);
		vector<int> b(n+7,0);
		int k=1;
		for(int j=i;j<=n;j++){
			if(b[a[j]]!=0&&b[a[j]]<k){
				k=b[a[j]]+1;
				c[k]=a[j];
			}else{
				b[a[j]]=k;
				c[k]=a[j];
				k++;
			}
		}
		for(int j=1;j<k;j++){
			d[c[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<d[i]<<" ";
	}
	return 0; 
}
