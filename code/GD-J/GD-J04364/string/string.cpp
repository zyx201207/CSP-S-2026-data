#include<bits/stdc++.h>
#define itn int
#define int long long
using namespace std;
const int N=2e5+10;
struct aa{
	int num;
	char c;
}s[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	itn n;
	cin>>n;
	int len=0;
	for(int i=1;i<=n;i++){
		cin>>s[i].num>>s[i].c;
		len+=s[i].num;
	}
	int ans=0,cnt1=1,cnt2=n;
	while(cnt1<cnt2){
		if(s[cnt1].num>s[cnt2].num){
			if(s[cnt1].c!=s[cnt2].c){
				s[cnt1].num-=s[cnt2].num;
				ans+=s[cnt2].num;
				cnt2--;
			}else{
				s[cnt1].num-=s[cnt2].num;
				cnt2--;
			}
			continue;
		}
		if(s[cnt1].num<s[cnt2].num){
			if(s[cnt1].c!=s[cnt2].c){
				s[cnt2].num-=s[cnt1].num;
				ans+=s[cnt1].num;
				cnt1++;
			}else{
				s[cnt2].num-=s[cnt1].num;
				cnt1++;
			}
			continue;
		}
		if(s[cnt1].c!=s[cnt2].c){
			ans+=s[cnt2].num;
			cnt2--;
			cnt1++;
		}else{
			cnt2--;
			cnt1++;
		}
	}
	cout<<ans;
	return 0;
}
