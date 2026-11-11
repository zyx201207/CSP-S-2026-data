#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
struct st{
	int a;
	char c;
}a[200005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);

	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].a>>a[i].c;
	}
	int cnt=0;
	st last={0,' '};
	for(int l=1,r=n;l<=r;l++,r--){
		if(last.a!=0){
			if(last.c==a[r].c){
				if(last.a>a[r].a){
					last.a-=a[r].a;
					a[r].a=0;
				}
				else{
					a[r].a-=last.a;
				}
			}
			else{
				if(last.a>a[r].a){
					last.a-=a[r].a;
					cnt+=last.a-a[r].a;
					a[r].a=0;
				}
				else{
					cnt+=a[r].a-last.a;
					a[r].a-=last.a;
				}
			}
		}
		if(a[l].c==a[r].c){
			if(a[l].a>a[r].a){
				last={a[l].a-a[r].a,a[l].c};
			}
			else if(a[l].a<a[r].a){
				last={a[r].a-a[l].a,a[l].c};
			}
			else last={0,' '};
		}
		else{
			if(a[l].a>a[r].a){
				cnt+=a[l].a-a[r].a;
				last={a[l].a-a[r].a,a[l].c};
			}
			else if(a[l].a<a[r].a){
				cnt+=a[r].a-a[l].a;
				last={a[r].a-a[l].a,a[r].c};
			}
			else{
				cnt+=a[l].a;
				last={0,' '};
			}
		}
	}
	cout<<cnt;
	return 0;
}
