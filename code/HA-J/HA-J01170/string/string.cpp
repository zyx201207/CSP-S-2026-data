#include <bits/stdc++.h>
using namespace std;
const int M=2e5+5;
int n;
struct note{
	int a;
	char c;
}b[M];
long long cnt;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i) cin>>b[i].a>>b[i].c;
	int l=1,r=n;
	while(l<=r){
		if(b[l].c!=b[r].c){
			if(b[l].a>b[r].a){
				b[r].c=b[l].c;
			}
			else b[l].c=b[r].c;
			cnt+=min(b[l].a,b[r].a);
		}
		if(b[l].c==b[r].c){
			if(b[l].a==b[r].a) {
				l++;
				r--;
			}
			else if(b[l].a>b[r].a){
				b[l].a-=b[r].a;
				r--;
			}else if(b[l].a<b[r].a){
				b[r].a-=b[l].a;
				l++;
			}
		}
	}
	cout<<cnt;
	return 0;
} 
