#include<bits/stdc++.h>
using namespace std;
long long n,m,a[5005],ans[5005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	for(int i = 1;i<=n;i++){
		long long b[5005];
		string w;
		for(int j = i;j<=n;j++){
			if(b[a[j]] != 0){
				string s = "";
				for(int z = 0;z<w.size();z++){
					if(w[z]-'0' == a[j])break;
					s+=w[z];
				}
				w = s;
			}
			b[a[j]]++;
			w+=a[j]+'0';
		}
		for(int j = 0;j<w.size();j++){
			ans[w[j]-'0']++;
		}
	}
	for(int i = 1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
}

