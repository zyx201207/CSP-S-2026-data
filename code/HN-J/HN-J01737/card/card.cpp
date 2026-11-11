#include <bits/stdc++.h>

using namespace std;

const int N=5e5+10;
int a[N];
bool shu[N];
int res[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		shu[a[i]]=1;
	}
	vector<int>z;
	for(int i=1;i<=n;i++){
		z.erase(z.begin(),z.end());
		for(int j=i;j<=n;j++){
			for(int k=0;k<z.size();k++){
				if(z[k]==a[j]){
					z.erase(z.begin()+k,z.end());
					break;
				}
			}
			z.push_back(a[j]);
		}
		for(int j=0;j<z.size();j++){
			res[z[j]]++;	
		}
	}
	for(int i=1;i<=m;i++){
		cout << res[i] <<' ';
	}
	return 0;
}
