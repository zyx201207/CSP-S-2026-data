#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
const int N=2e5+5;
int n;
struct node{
	ll a;
	char c;
} str[N];
ll ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> str[i].a >> str[i].c;
	}
	int l=1,r=n;
	while(l<r){
		ll mn=min(str[l].a,str[r].a);
		str[l].a-=mn;
		str[r].a-=mn;
		if(str[l].c!=str[r].c){
			ans+=mn;
		}
		if(str[l].a==0){
			l++;
		}
		if(str[r].a==0){
			r--;
		}
	}
	cout << ans;
	return 0;
}
