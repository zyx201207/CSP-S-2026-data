#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
#define ll long long
ll n,ans;
struct node{
	ll num;
	char word;
}a[maxn];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i].num >> a[i].word;
	int l=1,r=n,res=0;
	while(l<r){
		if(a[l].word==a[r].word){
			if(a[l].num<=a[r].num) a[l+1].num-=a[r].num-a[l].num;
			else a[r-1].num-=a[l].num-a[r].num;
			ans+=abs(a[l].num-a[r].num);
		}else{
			if(a[l].num<=a[r].num){
				a[l+1].num-=a[r].num-a[l].num;
				ans+=a[r].num;
			}else{
				a[r-1].num-=a[l].num-a[r].num;
				ans+=a[l].num;
			}
		}
		l++;
		r--;
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
return 0;
}

