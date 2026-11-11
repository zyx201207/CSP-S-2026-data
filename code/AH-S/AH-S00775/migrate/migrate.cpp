#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ultra unsigned __int128
int p[1000001],bf[1000001],dp[1000001],neo[100001];//Only APPLE Can Do!!!
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,d;
	scanf("%lld%lld",&c,&t);
	while(t--){
		scanf("%lld%lld",&n,&d);
	//	cout<<n<<" "<<d<<endl;
		for(int i = 1;i <= n;i++){
			scanf("%lld",&p[i]);
		//	cout<<p[i]<<" ";
			dp[i] = 0;
			bf[i] = 0;
		}
	//	cout<<endl;
		deque<int> q,id,emp;
		int tem = 1; 
	//	cout<<"bf:";
	//	for(int i = 1;i <= n;i++){
	//		cout<<bf[i]<<" ";
	//	}
	//	cout<<endl;	
	//	cout<<"前面唯一路径的个数：\n       ";
	//	//for(int i = 1;i <= n;i++)cout<<neo[i]<<" ";
	//	cout<<endl;
		q = emp;
		id = emp;
		int now = 1,ans = 0;
		q.push_back(p[1]);
		id.push_back(1);
		bf[1] = 1;
		for(int i = 2;i <= n;i++){
			while(now > 0 && p[i] - q.front() > d){
				q.pop_front();
				id.pop_front();
				now--;
			}
			q.push_back(p[i]);
			id.push_back(i);
			bf[i] = id.front();
			now++;
			if(!now || now < 3){
				continue;
			}else{
				ans += (min(bf[id.front() + 2],id.front()) - bf[id.front() + 1]); 
				//cout<<ans<<endl<<bf[id.front() + 2]<<" "<<id.front()<<" "<<bf[id.front() + 1]<<endl;
			}
		}
		/*for(int i = 1;i <= n;i++){
			cout<<dp[i]<<" ";
		}*/ 
		//cout<<endl;
		printf("%lld\n",ans);
	}
	return 0;
}

