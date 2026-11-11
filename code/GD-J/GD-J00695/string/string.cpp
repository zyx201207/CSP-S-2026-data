#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
ll a[N],ans;
int n;
char ch[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i]>>ch[i];
	}
	for(int L=1,R=n;L<R;){
		if(ch[L]!=ch[R]){
			if(a[L]>a[R]){
				a[L]-=a[R];
				ans+=a[R];R--;
			}else{
				a[R]-=a[L];
				ans+=a[L];L++;
			}
		}else{
			if(a[L]>a[R]){
				a[L]-=a[R];R--;
			}else{
				a[R]-=a[L];L++;
			}
		}
	}
	cout<<ans;
	return 0;
}
