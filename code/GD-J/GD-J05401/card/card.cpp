#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+7;
int n,t,l,m,a[N],ans[N],p[N]; 
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
   	cin>>n>>m;
   	for(int i=1;i<=n;i++){
   		cin>>a[i];	
	}t=n;
	while(t--){
		l++;
		memset(p,0,sizeof(p));
		stack<int>st;
		for(int i=l;i<=n;i++){
			int x=a[i];
			if(p[x]){
				while(1){
					if(st.top()!=x){
						p[st.top()]=0;
						st.pop();
					}else{
						p[x]=0;
						st.pop();
						break;
					}
				}
			}
			st.push(x);
			p[x]++;
		}for(int i=1;i<=m;i++){
			if(p[i]){
				ans[i]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
    return 0;
}
//10：40暴力打完，共48pts  
//10:47上厕所 观后感：石实厕所欢迎您（bushi
//10:想#13.14 但好像这个暴力已经可以解决#13-14
//时间复杂度O(nm)完全足够
//所以暴力共56pts
//目前为止总分(100+100+(55+x)+56)=311+x
//T1T2不报的情况下100%1= 
//fc.exe card.out card3.ans
