#include <bits/stdc++.h> 

using namespace std;


typedef unsigned long long ull;
typedef long long LL;
 
const int MAX = 5e5+10;
 
ull m;
int n,cnt;
LL a[MAX];
ull cost[MAX]; 
int b[MAX],c[MAX],ans[MAX];
vector<LL>q;
 
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	
	cin >>n>> m;
	
	for(int i =0 ;i<n; i++ ) cin >> a[i];
	
	sort(a,a+n);

	cnt = 1; 
	b[0]=0;
	c[0] = 1;
	q.push_back(a[0]);
	for(int i =1; i< n;i ++)
	{
		if(a[i]!=a[i-1]){
			q.push_back(a[i]);
			b[cnt] = i; 
			c[cnt] ++ ;
			cnt++;
		}
		else {
			c[cnt-1]++;
		}
	}

	cost[0] = 0;
	ans[0] = c[0];
	for(int i = 1;i <cnt; i++ )
	{
		cost[i] = cost[i-1]+b[i]*(q[i]-q[i-1]);
		ans[i] = b[i]+c[i]; 
	}
		
	int i =0 ;
	
	for(;i <cnt ;i++)
	{
		if(cost[i+1]>m) break;
	}
	
	if(i == 0) 
	{
		sort(c+0,c+cnt+1,greater<int>()) ;
		cout <<c[0] << endl ;
	}
	
	else if(i==cnt) cout << ans[i-1]<<endl;

	else{
		cout << ans[i]<< endl;
	}

	fclose(stdin);
	fclose(stdout);
	
	return 0 ; 
}
