#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,s[200005],cnt=0,l,r,lcnt,rcnt,ans=0,ll,rr,now=0;//l,r表示当前的左端点和右端点分别扩散到了哪个区间（下标），lcnt,rcnt表示当前左端点和右端点分别扩散到了下标为l,r的区间的右、左边第几个（含） 
char c[200005],ss[100000005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i]>>c[i];
		cnt+=s[i];
		for(int j=1;j<=s[i];j++){
			ss[j+now]=c[i];
		}
		now+=s[i];
	}
	if(cnt%2){
		for(int i=0;i<=(cnt>>1);i++){
			if(ss[((cnt+1)>>1)+i]!=ss[((cnt+1)>>1)-i]){
				ans++;
			}
		}
		cout<<ans;
//		for(int i=1,now=0;i<=n;i++){
//			now+=s[i];
//			if(now>=(cnt+1)/2){
//				l=i;
//				r=i;
//				lcnt=(cnt+1)/2-(now-s[i]);
//				break;
//			}
//		}
//		if(lcnt==1){
//			l--;
//			lcnt=0;
//			rcnt=1;
//		}
//		else if(lcnt==s[l]){
//			r++;
//			lcnt=1;
//			rcnt=0;
//		}
//		else{
//			ll=lcnt-1;
//			rr=s[l]-lcnt;
//			if(ll==rr){
//				l--;
//				r++;
//				lcnt=0;
//				rcnt=0;
//			}
//			else if(ll>rr){
//				r++;
//				rcnt=0;
//				lcnt-=rr; 
//			}
//			else{
//				l--;
//				rcnt=lcnt+ll;
//				lcnt=0;
//			}
//		}
	}
	else{
		for(int i=0;i<=(cnt>>1);i++){
			if(ss[(cnt>>1)+i]!=ss[(cnt>>1)-i]){
				ans++;
			}
		}
		cout<<ans;
//		for(int i=1,now=0;i<=n;i++){
//			now+=s[i];
//			if(now>cnt/2){
//				l=i;
//				r=i;
//				lcnt=cnt/2-(now-s[i]);
//				if(lcnt==1){
//					l--;
//					lcnt=0;
//					rcnt=2;
//				}
//				else{
//					ll=lcnt-1;
//					rr=s[l]-lcnt-1;
//					if(ll==rr){
//						l--;
//						r++;
//						lcnt=0;
//						rcnt=0;
//					}
//					else if(ll>rr){
//						r++;
//						rcnt=0;
//						lcnt-=rr; 
//					}
//					else{
//						l--;
//						rcnt=lcnt+1+ll;
//						lcnt=0;
//					}
//				}
//				break;
//			}
//			if(now==cnt/2){
//				l=i;
//				r=i+1;
//				lcnt=0;
//				rcnt=0;
//				break;
//			}
//		}
	}
//	while(l>0&&r<=n){
//		if(c[l]==c[r]){
//			ll=s[l]-lcnt;
//			rr=s[r]-rcnt;
//			if(ll==rr){
//				l--;
//				r++;
//				lcnt=0;
//				rcnt=0;
//			}
//			else if(ll>rr){
//				r++;
//				rcnt=0;
//				lcnt+=rr; 
//			}
//			else{
//				l--;
//				rcnt+=ll;
//				lcnt=0;
//			}
//		}
//		else{
//			ll=s[l]-lcnt;
//			rr=s[r]-rcnt;
//			if(ll==rr){
//				l--;
//				r++;
//				lcnt=0;
//				rcnt=0;
//			}
//			else if(ll>rr){
//				r++;
//				rcnt=0;
//				lcnt+=rr; 
//			}
//			else{
//				l--;
//				rcnt+=ll;
//				lcnt=0;
//			}
//			ans+=min(ll,rr);
//		}
//	}
//	cout<<ans;
	return 0;
}
/*
67 83 80 82 80 43 61 73 78 70
*/
