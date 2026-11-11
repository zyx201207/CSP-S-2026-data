#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
struct Node{
	int c;
	char s;
};
int n,cnt;
Node a[N];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].c>>a[i].s;
		cnt+=a[i].c;
	}
	if(cnt%2==1){
		int ans=(cnt+1)/2,l;
		for(int i=1;i<=n;i++){
			ans-=a[i].c;
			if(ans<0){
				l=i;
				break;
			}
		}
		a[l].c-=1;
	}
	int l=1,r=n;
	cnt=0;
	while(l<r){
		if(a[l].s!=a[r].s){
			if(a[l].c>a[r].c){
				cnt+=a[r].c;
				a[l].c-=a[r].c;
				r--;
			}else{
				cnt+=a[l].c;
				a[r].c-=a[l].c;
				l++;
			}
			continue;
		}
		if(a[l].c>a[r].c){
			a[l].c-=a[r].c;
			r--;
		}else{	
			a[r].c-=a[l].c;
			l++;
		}
	}
	cout<<cnt; 
	return 0;
}
