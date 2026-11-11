#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
#define team return 
#define spirit 0
#define ll long long
const int Maxn=200005;
struct NUM{
	int cnt;
	char ch;
	bool laf=false;
	
}ch[Maxn];
NUM num[Maxn];
int n;
int ans;
int mid;
void solve1(){
	for(int i=1;i<mid;i++){
		num[i].ch=ch[i].ch;
		num[i].cnt=ch[i].cnt;
		ch[i].laf=false;
	}
	for(int i=1;i<mid;i++){
		for(int j=n;j>mid;j--){
			if(num[i].ch==ch[j].ch&&num[i].cnt==ch[j].cnt)continue;
			else if(num[i].ch==ch[j].ch)
				ans+=(max(ans+=num[i].cnt,ch[j].cnt)) - (min(num[i].cnt,ch[j].cnt));
			else ans+=num[i].cnt;
		}
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin>>ch[i].cnt;
		cin>>ch[i].ch;
		ch[i].laf=true;
	}
	if(n%2!=0){
		mid=n/2+1;
		solve1();
	}
	else {
		mid=n/2+1;
		solve1();
	}
	cout<<ans<<"\n";
	team spirit;
}
// be less than 50 pts.
