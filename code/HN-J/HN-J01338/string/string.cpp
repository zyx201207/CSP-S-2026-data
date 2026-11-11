#include<bits/stdc++.h>
using namespace std;
struct node{
	long long num;
	char val;
}a[200005];
long long ans;
int n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i].num>>a[i].val;
	for(int i=1;i<=(n+1)/2;i++){
		if(a[i].val!=a[n+1-i].val){
			ans+=a[i].num;
			if(a[i].num!=a[n+1-i].num){
				//ans+=abs(a[n+1-i].num-a[i].num);
				a[n-i].num+=a[n+1-i].num-a[i].num;
				a[n+1-i].num=a[i].num;
			}
		}
		else if(a[i].num!=a[n+1-i].num){
			a[n-i].num+=a[n+1-i].num-a[i].num;
			a[n+1-i].num=a[i].num;
			
		}
	}
	cout<<ans;
	return 0;
}
