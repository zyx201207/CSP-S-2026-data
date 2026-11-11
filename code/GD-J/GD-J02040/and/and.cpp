#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;

const int MAXN = 300000;
const int LOG = 31;

int n,m;
int a[MAXN];


int limit,limit2k;

int k2cnt[100];
int k2cnt2[100];



bool cmp(int a,int b){
	return a > b;
}


int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	
	int tmp;
	
	for(int i=0;i<n;i++){
		cin >> tmp;
		a[i] = tmp;
		
		for(int j=0;j<LOG;j++){
			k2cnt[j] += ((tmp & 1ll << j) != 0);
		}
		
	}
	
	for(int i=0;i<LOG;i++)	{
		limit += (k2cnt[i] >= m) * (1ll << i);
		if(k2cnt[i] >= m) limit2k = (1ll << i);
	}
	
	for(int i=0;i<n;i++){
		if(a[i] < limit2k) a[i] = 0;
	}
	limit = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<LOG;j++){
			k2cnt2[j] += ((a[i] & 1ll << j) != 0);
		}
	}
	
	for(int i=0;i<LOG;i++)	{
		limit += (k2cnt2[i] >= m) * (1ll << i);
	}
	
	for(int i=0;i<n;i++){
		a[i] = a[i] & limit;
	}
	
	
	sort(a,a+n,cmp);
	

	
	int ans = limit;
	for(int i=0;i<m;i++){
		ans &= a[i];
	}
	
	cout << ans;
	return 0;
}
