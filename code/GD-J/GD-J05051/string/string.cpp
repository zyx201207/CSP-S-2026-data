#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define psb push_back
#define db double
const int N=2e5+5;
int n;
struct node{
	ll num;char c;
}a[N];
ll ans=0;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i].num>>a[i].c;
	int i=1,j=n;
	for(;i<j;){
		if(a[i].c==a[j].c){
			if(a[i].num==a[j].num)i++,j--;
			else if(a[i].num>a[j].num)
				a[i].num-=a[j].num,j--;
			else a[j].num-=a[i].num,i++;
		}
		else{
			if(a[i].num==a[j].num)ans+=a[j].num,i++,j--;
			else if(a[i].num>a[j].num)
				a[i].num-=a[j].num,ans+=a[j].num,j--;
			else a[j].num-=a[i].num,ans+=a[i].num,i++;
		}
	}
	cout<<ans;
return 0;}
