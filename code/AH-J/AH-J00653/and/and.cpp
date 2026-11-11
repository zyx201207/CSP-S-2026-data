 #include<bits/stdc++.h>
 using namespace std;
 long long n,m,a[200010],ans;
 vector<long long> v,t;
 int main()
 {
	 freopen("and.in","r",stdin);
	 freopen("and.out","w",stdout);
	 scanf("%lld%lld",&n,&m);
	 for(int i = 1;i <= n;i++)
	 {
		 scanf("%lld",a + i);
		 v.push_back(a[i]);
	 }
	 for(int i = 30;i >= 0;i--)
	 {
		 t.clear();
		 long long p = pow(2,i);
		 for(auto j : v)
		 {
			 if((j & p) != 0)
			 {
				 t.push_back(j);
			 }
		 }
		 if(t.size() >= m)
		 {
			 v = t;
			 ans += p;
		 }
	 }
	 cout << ans;
	 return 0;
 }
 //100pts
