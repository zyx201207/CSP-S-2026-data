#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 3e5 + 10;
const int N = 5e5 + 10;
int d[M];
int b[M];
int res[M];
int idx;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	int a[n];

	for(int i = 0;i<n;i++){
		cin>>a[i];
		d[a[i]]++;
		b[a[i]]++;
	}
	int tp = 0;
	bool fl = false;
	for(int i = 0;i<n;i++){
		fl = false;
		for(int j = i;j<n;j++){
			if(j == i){
				idx = j;
			}
			if(!fl){
				tp = a[j];
			}
			if(a[j] == tp){
				b[tp]--;
				if(b[tp] == 0){
					if(fl){
						idx = j;
						fl = false;	
					}	
				}else{
					fl = true;
				}
			}
		}
		for(int k = idx;k<n;k++){
			res[a[k]] ++;
		}
		for(int k = i;k<=m;k++){
			b[k] = d[k];
		}
		for(int l = 0;l<=i;l++){
			b[a[l]]--;
		}
	}
	for(int i = 1;i<=m;i++){
		cout<<res[i]<<" ";
	}
	return 0;
}
/*


*/
