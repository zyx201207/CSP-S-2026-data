#include<bits/stdc++.h>
using namespace std;
int ad[500100],n,m;
int cnt1[500100];
int cyc[500100][2]; 
int cnt2[500100];
int cun[300100];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >>m;
	for(int i = 1;i <= n;i++){
		cin >> ad[i];
		if(cnt1[ad[i]] == 0){
			cnt1[ad[i]] = i;
		}else{
			cyc[cnt1[ad[i]]][1] = i;
			cyc[i][0] = cnt1[ad[i]];
			cnt1[ad[i]] = i;
		}
	}
	int sum2 = 0;
	for(int i = 1;i <= n;i++){
		cnt2[i] = i;
		if(cyc[i][0]!=0){
			int h = cnt2[cyc[i][0]];
			sum2-=h;
		}
		cnt2[i]-=sum2;
		if(cyc[i][1] != 0){
			sum2+= cnt2[i];
		}
		cun[ad[i]] = max(cun[ad[i]],cnt2[i]);
	}
	for(int i = 1;i <= m;i++){
		cout << cun[i] << " ";
	}
	return 0;
}
