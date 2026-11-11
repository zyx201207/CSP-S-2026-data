#include <bits/stdc++.h>
#define int long long
using namespace std;
struct fn{
	char a;
	int b;
};
fn s[200005];
signed main (){
	freopen("string.in","r",stdin);
	freopen("string out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		char b;
		cin>>a>>b;
		s[i].a=b;
		s[i].b=a;
	}
	int x=1;
	int y=n;
	int sum=0;
	while(x<y){
		if(s[x].a==s[y].a){
			if(s[x].b==s[y].b){
				x++,y--;
				continue;
			}else{
//				sum+=min(s[x].b,s[y].b);
				s[x].b=abs(s[x].b-s[y].b);
				y--;
			}
		}else{
			if(s[x].b>s[y].b){
				sum+=min(s[x].b,s[y].b);
				s[x].b=abs(s[x].b-s[y].b);
				y--;
			}else{
				sum+=min(s[x].b,s[y].b);
				s[y].b=abs(s[x].b-s[y].b);
				x++;
			}
		}
	}
	cout<<sum;
	return 0;
}
