#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
int n;
ll tot;
struct{
	ll num;
	char word;
}a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i].num>>a[i].word;
	ll l=1,r=n;
	while(l<r){
		int k=min(a[l].num,a[r].num);
		if(a[l].word!=a[r].word)
			tot+=k;
		a[l].num-=k,a[r].num-=k;
		if(a[l].num==0) l++;
		if(a[r].num==0) r--;
	}
	cout<<tot;
	return 0;
}
