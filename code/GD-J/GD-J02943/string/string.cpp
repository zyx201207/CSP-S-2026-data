#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
#define int long long
int n,a[N],sum;
char c[N];
string s;
int cuc = 0;
int ans = 0;
void solve1(){
	for(int i = 1;i <= n;i ++){
		string ts = "";
		for(int j = 1;j <= a[i];j ++){
			ts += c[i];
		} 
		s += ts;
	}
	for(int i = 0;i <= (int)(s.length())/2-1;i ++){
		if(s[i]!=s[(int)(s.length())-1-i])ans++;
	}
	cout << ans;
}
void solve2(){
	for(int i = 1,j = n;i < j;){
		if(c[i] == c[j]){
			if(a[i]>a[j]){
				a[i]-=a[j];
				cuc+=a[j];
				j--;
				continue;		
			}
			else if(a[i] == a[j]){
				cuc+=a[i];
				i++;
				j--;
				continue;
			}
			else if(a[i] < a[j]){
				a[j] -= a[i];
				cuc+=a[i];
				i++;
				continue;
			}			
		}
		else{
			if(a[i]>a[j]){
				a[i]-=a[j];
				cuc+=a[j];
				ans += a[j]; 
				j--;
				continue;		
			}
			else if(a[i] == a[j]){
				ans += a[j];
				cuc+=a[j];
				i++;
				j--;
				continue;
			}
			else if(a[i] < a[j]){
				a[j] -= a[i];
				cuc+=a[i];
				ans += a[i]; 
				i++;
				continue;
			}	
		}
	}
	cout << ans;
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i ++){
		cin >> a[i] >> c[i];
		sum += a[i];
	}
	if(sum <= 3e5+10){
		solve1();
	} 
	else{
		solve2();
	}
	return 0;
}

/*
2
1000000006 a
1000000006 a
*/
