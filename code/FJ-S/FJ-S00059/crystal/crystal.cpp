#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN=5e5+3;
int n;
LL a[MAXN],m;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	LL cur=0,cur_cnt=0,res=0,max_cnt=0;
	for(int i=n;i>=1;i--){
		if(cur==a[i]) cur_cnt++;
		else{
			if(cur_cnt>max_cnt){
				max_cnt=cur_cnt;
				res=cur;
			}
			cur=a[i];
			cur_cnt=0;
		}
	}
	int index=-1;
	for(int i=1;i<=n;i++) if(a[i]==res){
		index=i;
		break;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(a[i]==res) ans++;
		if(a[i]>res) break;
	}
	while(m>0 && index>1){
		index--;
		m-=(res-a[index]);
		if(m>=0) ans++; 
	}
	cout << ans << '\n';
	return 0;
}
