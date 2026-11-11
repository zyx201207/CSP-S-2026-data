#include<bits/stdc++.h>
#define ll long long
#define fre(s) freopen(s".in" , "r" , stdin) , freopen(s".out" , "w" , stdout)

using namespace std;

int c , T;

ll n , d , ans , len , now , ansn;
ll a[2000005];

void dfs(int l , int r , int id , int cnt){
		
	//cout << cnt << " ";
	
	if(cnt > len)return;
	
	if(id == r){
		
		//cout << l << " " << r << " " << cnt << "\n";
		
		if(cnt == len)ansn ++;
		
		return;
		
	}
	
	for(int i = id + 1 ; i <= r ; i ++){
		
		if(a[i] - a[id] > d)break;
		
		//cout << l << " " << r << " " << i << " " << cnt + 1 << "\n"; 
		
		dfs(l , r , i , cnt + 1);
		
	}
	
}

int main(){

	fre("migrate");
	
	ios::sync_with_stdio(0);
	cin.tie(0) , cout.tie(0);
	
	cin >> c >> T;
	
	while(T --){
		
		ans = 0;
		
		cin >> n >> d;
		
		for(int i = 1 ; i <= n ; i ++)cin >> a[i];
		
		
		for(int i = 1 ; i <= n - 3 ; i ++)
			for(int j = i + 3 ; j <= n ; j ++){
				
				len ++;
				
				//cout << i << " " << j << " ";
				
				now = a[i];
				
				if(a[j] - a[i] > d)for(int k = i + 1 ; k <= j ; k ++)if(a[i] - now > d || k == j)len ++ , now = a[i];
				
				//cout << len << " ";
				
				dfs(i , j , i , 0);
				
				//cout << ansn << "\n"; 
				
				if(ansn == 2)ans ++;
				
				ansn = len = 0;
				
			}
				
		
		cout << ans << "\n";
		
	}

	return 0;

}
//人民萬歲 ，教員永垂不朽 
//今日長纓在手 ，何時敢縛蒼龍
