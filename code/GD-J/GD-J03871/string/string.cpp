#include <bits/stdc++.h>
using namespace std;
struct s{
	long long a;
	char c;
}str[200010];
const int MAXN=200010;
long long n,ans;
char c[MAXN];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> str[i].a >> str[i].c;
	}
	int l=1,r=n;
	while(l!=r){
		if(str[l].a<=str[r].a){
			if(str[l].c!=str[r].c){
				ans+=str[l].a;
			}
			str[r].a-=str[l].a;
			l++;
		}else{
			if(str[l].c!=str[r].c){
				ans+=str[r].a;
			}
			str[l].a-=str[r].a;
			r--;
		}
	}
	cout << ans;
	return 0;
}
