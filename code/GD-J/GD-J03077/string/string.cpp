#include <bits/stdc++.h>
using namespace std;
#define int long long
#define maxn 1000005
int n;
int a[maxn];
char c[maxn];
int cnt=0;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i] >> c[i];
	}
	for(int i=1,j=n;i<=j;){
		if(c[i]==c[j]&&a[i]==a[j]){
			i++,j--;
			continue;
		}else if(c[i]==c[j]&&a[i]!=a[j]){
			if(a[i]>a[j]){
				a[i]-=a[j];
				j--;
			}else{
				a[j]-=a[i];
				i++;
			}
		}else if(c[i]!=c[j]){
			if(a[i]>a[j]){
				c[j]=c[i];
				cnt+=a[j];
				a[i]-=a[j];
				j--;
			}else if(a[i]<a[j]){
				c[i]=c[j];
				cnt+=a[i];
				a[j]-=a[i];
				i++;
			}else{
				c[j]=c[i];
				cnt+=a[i];
				i++,j--;
			}
		}
	}
	cout << cnt << '\n';
	return 0;
} 
