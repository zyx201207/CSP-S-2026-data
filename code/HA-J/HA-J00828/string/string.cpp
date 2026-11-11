#include <bits/stdc++.h>
using namespace std;
//container
int n,t;
struct str{
	long long f,b;
	char c;
}s[200005];
//string __s="";
int a;
char c;
long long sum,ans;
//main
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	/*if(n < 10){
		for(int i=1;i<=n;++i){
			cin>>a>>c;
			for(int j=1;j<=a;++j){
				__s += c;
			}
			sum += a;
		}
		for(int i=(sum+1)/2;i<=sum;++i){
			if(__s[i] != __s[sum-i+1]){
				++ans;
			}
		}
		cout<<ans;
		return 0;
	}*/
	for(int i=1;i<=n;++i){
		cin>>a>>c;
		s[i].f = sum+1;
		sum += a;
		s[i].b = sum;
		s[i].c = c; 
	}
	for(int i=1;i<=n;++i){
		if(s[i].b <= (sum+1)/2){
			++t;
			continue;
		}
		/*if(s[i].f <= (sum+1)/2){
			++t;
		}*/
		for(;t>0;--t){
			if(s[t].b < sum+1-s[i].b){
				++t;
				break;
			}
			if(s[t].c == s[i].c){
				continue;
			}
//			cout<<1<<" ";
			ans += min(sum+1-s[i].f,s[t].b) - max(sum+1-s[i].b,s[t].f) + 1;
		}
	}
	if(n % 2 == 1){
		++ans;
	}
	cout<<ans;
	return 0;
}

