#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

const int N=2e5+5;
int a[N];
int maxn=INT_MIN;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ll n,m;
	cin >> n >> m;
	for(int i=1; i<=n; i++){
		cin >> a[i];
	}
	if(m==2){
		for(int i=1; i<=n; i++){
			for(int j=i+1; j<=n; j++){
				maxn=max(maxn,(a[i]&a[j]));
			}
		}
	}
	if(m==3){
		for(int i=1; i<=n; i++){
			for(int j=i+1; j<=n; j++){
				for(int k=j+1; k<=n; k++){
					maxn=max(maxn,(a[i]&a[j]&a[k]));
				}
			}
		}
	}

	cout << maxn;

	return 0;
}

