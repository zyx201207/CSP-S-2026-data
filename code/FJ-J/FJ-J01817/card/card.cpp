#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500005];
int pl[500005];
vector<int> cad;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int now=a[j];
			int pos=-1;
			for(int k=0;k<cad.size();k++){
				if(cad[k]==now) {
					pos=k;break;	
				}
			}
			if(pos!=-1){
				for(int k=1;k<=cad.size()-pos;k++){
					cad.pop_back();
				}	
			}
			cad.push_back(now);
		} 
		int pos=-1;
		for(int k=0;k<cad.size();k++){
			if(cad[k]<=m) pl[cad[k]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<pl[i]<<' ';
	}
	return 0;
} 
