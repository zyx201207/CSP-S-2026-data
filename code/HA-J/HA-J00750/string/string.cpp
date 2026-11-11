#include<bits/stdc++.h>
using namespace std;
#define int long long
struct w{
	int y;
	char b;
};
w a1[200005];
bool a2[200005];
int n,ans,sh;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    scanf("%lld",&n);
    for(int p=1; p<=n; p++){
    	scanf("%lld",&a1[p].y);
    	cin>>a1[p].b;
	}
	int o=0,r=1,l=n,q=0,j=0;
	if(a1[r].y<=a1[l].y) o=a1[l].y,j=n;
	else o=a1[r].y,j=r;
	while(q<=n && r!=l){
		if(j==r){
			if(o<a1[l].y) o=a1[l].y,j=l;
		}
		else{
			if(o<a1[r].y) o=a1[r].y,j=r;
		}
		if(a1[r].b==a1[l].b){
			if(j==r){
				o-=a1[l].y;
				a1[r].y-=a1[l].y;
				l--;
				q++;
			}
			else{
				o-=a1[r].y;
				a1[l].y-=a1[r].y;
				r++;
				q++;
			}
		}
		else{
			if(j==r){
				o-=a1[l].y;
				a1[r].y-=a1[l].y;
				ans+=a1[l].y;
				l--;
				q++;
			}
			else{
				o-=a1[r].y;
				a1[l].y-=a1[r].y;
				ans+=a1[r].y;
				r++;
				q++;
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
