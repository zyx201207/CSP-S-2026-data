#include<bits/stdc++.h>
#define int long long

using namespace std;
const int N=5e5+6;
int n,m;
int a[N];
int ans=0,num=0;
int now;//当前该遍历a[now] 

bool cmp(int x,int y){
	return x>y;
}

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
//	int mm=m;	/////
	for(int i=1;i<=n;i++)	cin>>a[i];
	sort(a+1,a+1+n,cmp);
	ans=1;
	for(now=2;now<=n;now++){
		if(m>=a[1]-a[now]){
			ans+=1;
			m-=a[1]-a[now];
		}
		else	break;
	}
//	cerr<<"-->"<<ans<<" "<<mm-m<<endl;	////
	int lst=ans;
	for(int i=2;i<=n;i++){
		int temp=lst-1;
		m+=(a[i-1]-a[i])*temp;
		for(;now<=n;now++){
			if(m>=a[i]-a[now]){
			//	 cerr<<now<<" ";	//
				temp+=1;
				m-=a[i]-a[now];
			}
			else	break;
		}
		ans=max(ans,temp);
		lst=temp;
	//	cerr<<"-->"<<temp<<" "<<mm-m<<endl;	////
	}
	cout<<ans;
	return 0;
} 
