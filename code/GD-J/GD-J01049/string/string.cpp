 #include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int t; //t段 
long long ans = 0;
struct{
	long long n;
	char c;
}a[N];
int main(){
//	freopen("string.in", "r", stdin);
//	freopen("string.out", "w", stdout);
	
	cin >> t;
	for(int i = 0;i < t;i++){
		cin >> a[i].n >> a[i].c;
	}
	int l, r = t - 1;
	while(l < r){
	 	if(l == r) break;
	 	//两者字母不等 
	 	if(a[l].c != a[r].c) {
	 		
			if(a[l].n > a[r].n){//l大 
				ans += a[r].n;//改变r个 
				a[r].n = 0, a[l].n = a[l].n - a[r].n;//r为零, l等于差 
			}
			else if(a[l].n < a[r].n){//r大 
				ans += a[l].n;//改变l个
				a[l].n = 0, a[r].n = a[r].n - a[l].n;//l为零, r等于差 
			}
			else{//两者相等 
				ans += a[l].n;
				a[r].n = 0, a[l].n = 0;//都为零 
			}
		}
		//两者字母相等 
		else {
			if(a[l].n > a[r].n){//l大 
				a[r].n = 0, a[l].n = a[l].n - a[r].n;//r为零, l等于差 
			}
			else if(a[l].n < a[r].n){//r大 
				a[l].n = 0, a[r].n = a[r].n - a[l].n;//l为零, r等于差 
			}
			else if(a[l].n < a[r].n && l != r){//两者相等，且l != r
				a[r].n = 0, a[l].n = 0;//都为零 
			}
		}
		if(a[l].n == 0) l++;
		if(a[r].n == 0) r--; 
	}
	cout << ans;
	return 0; 
} 
