#include<bits/stdc++.h>
using namespace std;
struct node{
	long long id,len;
	char s;
}a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long n,ans=0;
	cin>>n;
	a[0].len=1;
	for(int i=1;i<=n;i++){
		cin>>a[i].len>>a[i].s;
		a[i].id=a[i-1].id+a[i-1].len;
	}
	for(long long i=1,j=n;i<=j;){
		if(a[i].s==a[j].s){
			if(a[i].len>a[j].len){
				a[i].len-=a[j].len;
				a[j].len=0;
				j--;
			}
			else{
				a[j].len-=a[i].len;
				a[i].len=0;
				i++;
			}
		}
		else{
			if(a[i].len>a[j].len){
				ans+=a[j].len;
				a[i].len-=a[j].len;
				a[j].len=0;
				j--;
			}
			else{
				ans+=a[i].len;
				a[j].len-=a[i].len;
				a[i].len=0;
				i++;
			}
		}
	}
	cout<<ans;
	return 0;
}
