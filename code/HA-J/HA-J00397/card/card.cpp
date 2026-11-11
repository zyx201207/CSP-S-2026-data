#include <bits/stdc++.h>
using namespace std;
long long n,m,i,j,c;

vector<int> a[100000];


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
//	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	for(i = 0;i<n;i++){
		cin>>c;
		a->push_back(c);
		for(j = 0;j<i;j++){
			if(a[j] == a[i]){
				;
			}
		}
	}

	return 0;
}
