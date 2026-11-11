#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
int n;
int a[N];
char s[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in" ,"r" ,stdin);
	freopen("string.out" ,"w" ,stdout);
	cin >> n;
	for(int i=1;i <= n;i++){
		cin >> a[i] >> s[i];
	}
	int i=1 ,j=n;
	ll ans=0;
	while(i < j){
		if(s[i]==s[j]){
			if(a[i]>a[j]){
				a[i]-=a[j];
				j--;
			}else if(a[i] < a[j]){
				a[j]-=a[i];
				i++;
			}else{
				i++ ,j--;
			}
		}else{
			if(a[i]>a[j]){
				ans+=a[j];
				a[i]-=a[j];
				j--;
			}else if(a[i]<a[j]){
				ans+=a[i];
				a[j]-=a[i];
				i++;
			}else{
				ans+=a[j];
				i++ ,j--;
			} 
		}
	}
	cout << ans << '\n';
	return 0;
} 
