//GZ-J00350 贵阳市第三实验中学 郑思成
#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f
#define INF 0x3f3f3f3f3f3f
using namespace std;
int n;
ll a,cnt,rescnt,resi,resc,ans;
char c;
string s=" ";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int i=1;i<=a;i++){
			s+=c;
		}
		cnt+=a;
	}
	if(cnt%2!=0){
		rescnt=cnt/2+1;
//		for(int i=1;i<=n;i++){
//			if(cnt[i]>=rescnt){
//				resi=i;
//				resc=cnt[i]-rescnt;
//			}
//		}
		for(int i=1;i<=rescnt-1;i++){
			int u1=rescnt-i,u2=rescnt+i;
			if(u1==0){break;}
			if(s[u1]!=s[u2]){
				ans++;
			}
		}
	}
	if(cnt%2==0){
		rescnt=cnt/2;
//		for(int i=1;i<=n;i++){
//			if(cnt[i]>=rescnt){
//				resi=i;
//				resc=cnt[i]-rescnt;
//			}
//		}
		for(int i=1;i<=rescnt;i++){
			int u1=rescnt+1-i,u2=rescnt+i;
			if(s[u1]!=s[u2]){
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}



