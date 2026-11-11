#include<bits/stdc++.h> 
using namespace std;
const int N = 2e5 + 10;
long long ans;
int n;
long long a[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
//	std::sycn_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	scanf("%lld",&n);
	for(int i = 1;i <= n;i++){
		scanf("%lld%s",&a[i],&c[i]);
//		cout<<a[i]<<" "<<c[i]<<'\n';
	}
	for(int i = 1,j = n;i <= n && j > 0;){
		if(i >= j){
			break;
		}
		if(c[i] != c[j]){
			if(a[i] <= a[j]){
				c[i] = c[j];
				ans += a[i];
				a[j] = max(0ll,a[j] - a[i]);
				i++;
				if(a[j] == 0){
					j--;
				}
			}
			else{
				c[j] = c[i];
				ans += a[j];
				a[i] = max(0ll,a[i] - a[j]);
				j--;
				if(a[i] == 0){
					i++;
				}
			}
		}
		else{
			if(a[i] <= a[j]){
				a[j] = max(0ll,a[j] - a[i]);
				i++;
				if(a[j] == 0){
					j--;
				}
			}
			else{
				a[i] = max(0ll,a[i] - a[j]);
				j--;
				if(a[i] == 0){
					i++;
				}
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
