#include<bits/stdc++.h>
using namespace std;
const int MAXN = 200010;
struct node{
	long long cnt;
	char ch;
}a[MAXN];
long long n,ans,pos1,pos2,cnt1,cnt2;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i<=n;i++) cin >> a[i].cnt >> a[i].ch;
	pos1 = 1,pos2 = n;
	while(pos1<pos2){
		int len1 = (a[pos1].cnt-cnt1),len2 = (a[pos2].cnt-cnt2);
		char ch1 = a[pos1].ch,ch2 = a[pos2].ch;
		if(len1>=(a[pos2].cnt-cnt2)){
			while(len1>=(a[pos2].cnt-cnt2)){
				if(pos1>=pos2) break;
				if(ch1!=a[pos2].ch) ans += (a[pos2].cnt-cnt2);
				len1 -= (a[pos2].cnt-cnt2),pos2--;
				cnt2 = 0;
			}
			if(pos1>=pos2) break;
			if(ch1!=a[pos2].ch) ans += len1;
			cnt2 += len1;
			pos1++,cnt1 = 0;
		}
		else{
			while(len2>=(a[pos1].cnt-cnt1)){
				if(pos1>=pos2) break;
				if(ch2!=a[pos1].ch) ans += (a[pos1].cnt-cnt1);
				len2 -= (a[pos1].cnt-cnt1),pos1++;
				cnt1 = 0;
			}
			if(pos1>=pos2) break;
			if(ch2!=a[pos1].ch) ans += len2;
			cnt1 += len2;
			pos2--,cnt2 = 0;
		}
	}
	cout << ans;
	return 0;
}
