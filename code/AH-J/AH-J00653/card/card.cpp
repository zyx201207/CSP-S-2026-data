 #include<bits/stdc++.h>
 using namespace std;
 long long n,m,a[500010],ans[300010];
 bool ok = 1;
 void solve()
 {
	 long long cnt[300010] = {0};
	 for(int i = 1;i <= n;i++)
		 cnt[a[i]] = i;
	 for(int i = 1;i <= m;i++)
		printf("%lld ",cnt[i]);
     exit(0);
 }
 int main()
 {
	 freopen("card.in","r",stdin);
	 freopen("card.out","w",stdout);
	 scanf("%lld%lld",&n,&m);
	 for(int i = 1;i <= n;i++)
	 {
		scanf("%lld",a + i);
		if(a[i] > a[i + 1])ok = 0;
	 }
	 //if(ok)solve();
	 for(int lt = 1;lt <= n;lt++)//第i局
	 {
		 deque<long long> dq;
		 bool vl[300010] = {0};
		 for(int i = lt;i <= n;i++)
		 {
			 if(vl[a[i]])
			 {
				 while(!dq.empty() && dq.back() != a[i])
				 {
					 vl[dq.back()] = 0;
					 dq.pop_back();
				 }
				 dq.pop_back();
			 }
			 dq.push_back(a[i]);
			 vl[a[i]] = 1;
		 }
		 for(int i = 0;i < dq.size();i++)
			 ans[dq[i]]++;
	 }
	 for(int i = 1;i <= m;i++)
		printf("%lld ",ans[i]);
	 return 0;
 }
 //100+100+100+(52~68)=(352~368)pts!!
