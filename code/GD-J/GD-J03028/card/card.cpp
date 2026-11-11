#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int len=n;
	int w=0;
	int card[1010000]={};
	for(int i=0;i<n;i++){
		cin >> card[i];
	}
	int cnt[1010000]={};
	int dc[1010000]={};
	int i=1;
	for(int i=0;i<m;i++){
		cout << n<<" ";
	}
	return 0;
}
 
