#include<bits/stdc++.h>

using namespace std;

const int MAXN  = 5e5+5;
const unsigned long long MAXA = 1e6;

int n;//n颗水晶
unsigned long long m; //最多m次操作(m一定不是负数） 
long long a[MAXN];
vector<int> a_2;

long long num[MAXA];

long long pre_sum[MAXN]; //前缀和求和 

bool typeA=1; 

int main(){

	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin>>n>>m;
	pre_sum[0] = 0; 
	
	if(m==0){
		long long ans = 0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			num[a[i]]++;
			ans = max(ans,num[a[i]]);
		}
		cout<<ans<<endl;
		return 0;
	}
	
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a_2.push_back(a[i]);
		pre_sum[i] = pre_sum[i-1]+a[i];
		if(a[i]!=i){
			typeA = 0; 
		}
	}
	
		
	if(typeA == 1){
		//!最多就只能有n个，最大的那一个不应该被操作 
		for(int k=n-1;k>=1;k--){  
			if(pre_sum[k]<=m){ //找到最大可实现的数量 
				cout<<k+1; //!本来就有一个不需要操作的 
				return 0;
			}
		}
	} 
	else{
		long long ans = 0;
		while(m>0){
			sort(a_2.begin(),a_2.end());
			int id = a_2[0];
			int idex = upper_bound(a_2.begin(),a_2.end(),id)-a_2.begin();
			int c = a_2[idex] - a_2[0];
			if(m>=c){
				m -= c;
				a_2[0] += c;
			}
			else{break;}
		}
		sort(a_2.begin(),a_2.end());
		for(int i=0;i<n;i++){
			if(a_2[i]==a_2[0]){
				ans++;
			}
		}
		cout<<ans;

	}
	
	
	return 0;
}

