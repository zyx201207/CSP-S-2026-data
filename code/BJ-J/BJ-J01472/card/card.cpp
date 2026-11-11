#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,a[500005],t[100005];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		vector<int> v;
		for(int j=i;j<=n;j++){
			for(int k=0;k<v.size();k++){
				if(a[j]==v[k]){
					for(int l=k;l<v.size();l++){
						t[v[l]]--;
						v[l]=0;
					}
					break;
				}
			}
			v.push_back(a[j]);
			t[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<t[i]<<' ';
	}
}
