#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5+10;
struct node{
	int s;
	char e;
	
}a[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	//int sum = 0;
	for(int i = 1;i <= n;i ++){
		cin >> a[i].s >> a[i].e;
		//sum += a[i].s;
		
			
	}
	
	int i = 1;
	int j = n;
	int ans = 0;
	while(i < j){
		if(a[i].e == a[j].e){
			if(a[i].s > a[j].s){
				a[i].s = a[i].s - a[j].s;
				j --;
			}else if(a[i].s < a[j].s){
				a[j].s = a[j].s - a[i].s;
				i ++;
			}else{
				i ++;
				j --;
			}
			
		}else{
			if(a[i].s > a[j].s){
				ans += a[j].s;
				a[i].s = a[i].s - a[j].s;
				j --;
			}else if(a[i].s < a[j].s){
				ans += a[i].s;
				a[j].s = a[j].s - a[i].s;
				i ++;
			}else{
				ans += a[j].s;
				i ++;
				j --;
				
			}
		}
		
		
	}
	cout<<ans;
	return 0;
}

