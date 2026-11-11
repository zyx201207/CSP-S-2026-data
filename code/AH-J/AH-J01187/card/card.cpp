#include<iostream>
#include<string>
using namespace std;
#define ll long long
ll n,m;
char c=' ';
string has="",ans="";
int cnt[30005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>c;
		has+=c;
	}
	for(ll ju=1;ju<=n;ju++){
		ans="";
		for(int take=ju/*正在拿的牌的地址*/;take<has.length();take++){
			if(ans.find(has[take]) != -1){
				int t=ans.length();
				for(int i=ans.find(has[take]);i<t-1;i++){
					ans=ans.substr(0,ans.length()-1);
				}
			}else{
				ans+=has[take];
			}
		}
		for(int i=0;i<ans.length();i++){
			cnt[ans[i]-'0']+=1;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" "<<endl;
	} 
	return 0;
}


