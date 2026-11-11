#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],win[300005],qian[500005],shu[300005],t[300005],pri[300005]; 
int ll,rr,er;
int pan[500005];
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/
struct sd{
	int xia,zhi;
};
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	memset(shu,-1,sizeof(shu));
	scanf("%lld%lld",&n,&m);
	for(int i = 1;i<=n;i++){
		scanf("%lld",&a[i]);
		qian[i]=shu[a[i]];
		shu[a[i]]=i;
	}
	for(int i = 0;i<n;i++){
		memset(pan,0,sizeof(pan));
		memset(pri,0,sizeof(pri));
		stack<sd> sta;
		for(int j = i+1;j<=n;j++){
			er =j;
			if(qian[j]!=-1&&pan[qian[j]]==0&&qian[j]>i){
				sd st=sta.top();
				while(st.xia>=er){
					pan[st.xia]=1;
				} 
			}
			else{
				sta.push({j,a[j]});
			}
			/*
			if(qian[j]!=-1&&qian[j]>rr&&qian[j]){
				ll=qian[j];
				rr=j;
				t[qian[j]]++;
				t[j+1]--;
			} */
			/*
			else if(qian[j]!=-1&&qian[j]>rr){
				rr=j;
				t[qian[j]]++;
				t[j+1]--;
			}
			*/
		} 
		for(int j=i+1;j<=n;j++){
			if(pan[j]==0){
				pri[a[j]]=1;
			}
		}
		for(int j = 1;j<=m;j++){
			if(pri[j]){
				win[j]++;
			}
		}
		//cout<<"-----------------"<<endl;
	}
	cout<<endl;
	for(int i = 1;i<=m;i++){
		cout<<win[i]<<" ";
	}
	return 0;
}
