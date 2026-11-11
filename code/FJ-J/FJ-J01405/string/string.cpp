#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const int N=2e5+7;
int n,l,r;
ull ans;
struct str{
	int a;
	char c;
}s[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;l=1;r=n;
	for (int i=1;i<=n;i++) cin>>s[i].a>>s[i].c;
	while (l<r){
		if (s[l].c==s[r].c){
			if (s[l].a>s[r].a){
				s[l].a-=s[r].a;
				s[r].a=0;
				r--;
			}else{
				s[r].a-=s[l].a;
				s[l].a=0;
				l++;
			}continue;
		}if (s[l].a>s[r].a){
			s[l].a-=s[r].a;
			ans+=s[r].a;
			s[r].a=0;
			r--;
		}else{
			s[r].a-=s[l].a;
			ans+=s[l].a;
			s[l].a=0;
			l++;
		}
	}cout<<ans;
	return 0;
}
