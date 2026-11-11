#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define ull unsigned long long 
#define endl '\n' 
const int M=5e5+67;
int n,m;
int a[M];
map<int,int> ans;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
	
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	vector<int> b;
	for(int k=1;k<=n;k++){
		for(int i=k;i<=n;i++){
			for(int j=0;j<b.size();j++){
				if(b[j]==a[i]){
					for(int u=j;u<b.size();u++){
						b.pop_back();
					}
					break;
				}
			}
			b.push_back(a[i]);
		}
		for(int i=0;i<b.size();i++){
			int x=b[i];
			ans[x]++;
		}
		b.clear();
	}
	for(int i=1;i<=m;i++){
		cout << ans[m] << " ";
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}


