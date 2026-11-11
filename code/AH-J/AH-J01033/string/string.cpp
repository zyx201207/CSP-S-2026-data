#include<bits/stdc++.h>
using namespace std;
struct node{
	long long st;
	long long ed;
	char ch;
};
node a[200005];
int main(){
	//ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	long long tot = 0,ans = 0;
	for(int i = 1;i <= n;i ++){
		long long t;
		cin >> t >> a[i].ch;
		a[i].st = tot + 1;
		tot += t;
		a[i].ed = tot;
		//cout << i << a[i].ch << ' ' << a[i].st << ' ' << a[i].ed << endl;
	}
	long long post = tot/2;
	node now = a[1],dow = a[n];
	long long posn = 1,posd = tot;
	long long i = 1;
	long long j = n;
	//cout << tot;
	//cout << posn << ' ' << posd << endl;
	while(1){
		while(!(posn >= now.st && posn <= now.ed)){
			i ++;
			now = a[i];
		}
		while(!(posd >= dow.st && posd <= dow.ed)){
			//cout <<"posd:" << posd << ' '<< j << dow.ch << ' ' << dow.st << "  jk  " << dow.ed << endl;
			j --;
			dow = a[j];
		}
		//cout << posn << ' ' << posd << endl;
		if(posn - 1 == posd || posn == posd)break;
		else if(posn >= posd){
			if(tot%2 == 0){
				
			}
		}
		else{
			long long manage = min(now.ed - posn + 1,posd - dow.st + 1);
			if(posn + manage - 1 > posd - manage){
				 manage = min(post - posn + 1,posd - post + 1);
			}
			posn += manage;
			posd -= manage;
			//cout << now.ch << ' ' << dow.ch << ' ' << manage << "\n";
			ans += manage*(now.ch != dow.ch);
		}
	}
	cout << ans;
	return 0;
}

