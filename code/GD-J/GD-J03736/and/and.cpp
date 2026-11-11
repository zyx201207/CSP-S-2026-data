#include<bits/stdc++.h>
#define int long long
#define endl '/n'
using namespace std;
int l[200005];
signed main(){
	//freopen(and.in,"r",stdin);
	//freopen(and.out,"w",stdout);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,m;
	cin>>n>>m;
	for(int i = 0;i < n;i++){
		cin>>l[i];
	}
	int max_ = 0;
	if(m == 1){
		for(int i = 0;i < n;i++){
			max_ = max(max_,l[i]);
		}
	}
	else if(m == 2){
		for(int i = 0;i < n;i++){
			for(int j = i + 1;j < n;j++){
				max_ = max(max_,l[i] & l[j]);
			}
		}
	}
	else if(m == 3){
		for(int i = 0;i < n;i++){
			for(int j = i + 1;j < n;j++){
				for(int a = j + 1;a < n;a++){
					max_ = max(max_,l[i] & l[j] & l[a]);
				}
			}
		}
	}
	cout<<max_;
	return 0;
} 
