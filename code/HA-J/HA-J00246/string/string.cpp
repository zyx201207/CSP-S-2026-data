#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n;
struct s{
	int len;
	char c;
}t[N];
int a;
char ch;
int cnt;
int ans;
int i,j;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a>>ch;
		if(ch!=t[cnt].c){
			cnt++;
			t[cnt].len=a;
			t[cnt].c=ch;
		}else{
			t[cnt].len+=a;
		}
	}
	if(cnt==1){
		cout<<0;
		return 0;
	}
	i=1;
	j=cnt;
	while(i<j){
		if(t[i].len==t[j].len&&t[i].c==t[j].c){
			i++,j--;
		}else if(t[i].len==t[j].len&&t[i].c!=t[j].c){
			ans+=t[j].len;
			i++;
			j--;
		}else if(t[i].len!=t[j].len){
			if(t[i].len<t[j].len){
				int la=t[j].len;
				int lb;
				while(la>0){
					lb=t[i].len;
					if(lb<=la&&t[i].c!=t[j].c){
						ans+=lb;
						la-=lb;
						i++;
					}else if(lb<=la&&t[i].c==t[j].c){
						la-=lb;
						i++;
					}else if(lb>=la&&t[i].c==t[j].c){
						t[i].len-=la;
						la=0;
					}else{
						ans+=la;
						t[i].len-=la;
						la=0;
					}
				}
				j--;
			}else{
				int la=t[i].len;
				int lb;
				while(la>0){
					lb=t[j].len;
					if(lb<=la&&t[j].c!=t[i].c){
						ans+=lb;
						la-=lb;
						j--;
					}else if(lb<=la&&t[j].c==t[i].c){
						la-=lb;
						j--;
					}else if(lb>=la&&t[j].c==t[i].c){
						t[j].len-=la;
						la=0;
					}else{
						ans+=la;
						t[j].len-=la;
						la=0;
					}
				}
				i++;
			}
		}
	}
	cout<<ans;
	return 0;
}
