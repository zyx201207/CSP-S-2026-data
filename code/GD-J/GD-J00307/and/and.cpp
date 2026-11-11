#include<bits/stdc++.h>
using namespace std;

long long f(long long a,long long b){
	if (b == 0)return a;
	else return f(a*2,b-1);
}
int mx = f(1,30);
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	vector<vector<int>> nums(32);
	for (int i =0;i < n;i++){
		int a,b;
		cin>>a;
		b = a;
		int cnt = 0;
		while (a >= 2)
		{
			cnt++;
			a >>= 1;
		}
		nums[cnt].push_back(b);
	}
	int ans = -1;
	for (int i = 31;i > 0;i--)
	{
		if (m == 0)break;
		vector<int> cur = nums[i];
		if (cur.size() == 1){
			int c = 0,d;
			int p = cur[0] - f(1,i);
			d = p;
			while (p >= 2){
				c++;
				p >>= 1;
			}
			if (i > 0)nums[c].push_back(d);
			//if (i > 0)nums[i-1].push_back(1);
			else {
				ans &= cur[0];
				break;
			}
			continue;
		}
		if (cur.size() == 0)continue;
		if (cur.size() > m){
			sort(cur.begin(),cur.end());
			for (int j = cur.size()-1;j >= cur.size()-m;j--){
				if (ans = -1)ans = cur[j];
				else ans &= cur[j];
				//cout<<"Ñ¡Ôñ"<<cur[j]<<" ";
			}
			m = 0;
		}
		else {
			for (int j = 0;j < cur.size();j++)
			{
				if (ans = -1)ans = cur[j];
				else ans &= cur[j];
				//cout<<"Ñ¡Ôñ"<<cur[j]<<" ";
			}
			m -= cur.size();
		}
		
	}
	//cout<<(524288 & 262144)<<endl; 
	
	cout<<ans;




return 0;	
} 
