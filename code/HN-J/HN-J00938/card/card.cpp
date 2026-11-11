#include<bits/stdc++.h>
#define int long long  
//voidÄ©Î²Òª¼Óreturn;
using namespace std;
const int N=5e5+10;
int n,m;
int a[N];
int cnt[(int)3e5+10];
void game(int x){
	vector<int>cs;
	for(int i=x;i<=n;i++){
		cs.push_back(a[i]);
		for(int j=0;j<(int)cs.size();j++){
			if(cs[j]==a[i]){
				cs.erase(cs.begin()+j,cs.end()-1);
				break;
			}
		}
	}
	for(const int &y:cs){
		cnt[y]++;
	}
	return;
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		game(i);
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<' ';
	}
	return 0;
}

