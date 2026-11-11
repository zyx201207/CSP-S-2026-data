 #include <iostream>
 #include <vector>
 using namespace std;
 bool flag;
 int n,m,cur;
 vector<int>ps;
 void ans()
 {
	int res=ps[0];
	for(auto i:ps)
		res&=i;
	cout << res;
	exit(0);
 }
 int main()
 {
	ios::sync_with_stdio(false);cin.tie(nullptr);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i<=n;i++)
	{
		int tmp;
		cin >> tmp;
		if(tmp)
		{
			cur++;
			ps.push_back(tmp);
		}
	}
	if(cur<m)
	{
		cout << 0;
		return 0;
	}
	for(int i = 30;i>=0;i--)
	{
		vector<int>tmp;
		for(int j:ps)
			if(j&(1<<i))
				tmp.push_back(j);
//		cout << ps.size() << ' ' << tmp.size() << endl;
		if(tmp.size()>=m)
		{
			ps=tmp;
			if(tmp.size()==m)ans();
		}
	}
	ans();
	return 0;
 }
