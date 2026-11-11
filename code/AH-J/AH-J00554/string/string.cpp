#include<bits/stdc++.h>
using namespace std;
long long ans;
long long n,cnt;
struct Node{
	long long num;
	char id;
}a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		long long x;
		char y;
		scanf("%lld",&x);
		cin>>y;
		if(y==a[cnt].id)a[cnt].num+=x;
		else{
			cnt++;
			a[cnt].id=y;
			a[cnt].num=x;
		}
	}
	long long l=1,r=cnt;
	while(l!=r){
		if(a[l].id==a[r].id){
			if(a[l].num>a[r].num){
				a[l].num-=a[r].num;
				a[r].num=0;
				r--;
			}
			else if(a[l].num<a[r].num){
				a[r].num-=a[l].num;
				a[l].num=0;
				l++;
			}
			else {
				l++;
				r--;
			}
		}
		else{
			if(a[l].num>a[r].num){
				ans+=a[r].num;
				a[l].num-=a[r].num;
				a[r].num=0;
				r--;
			}
			else if(a[l].num<a[r].num){
				ans+=a[l].num;
				a[r].num-=a[l].num;
				a[l].num=0;
				l++;
			}
			else {
				ans+=a[l].num;
				l++;
				r--;
			}
		}
	}
	cout<<ans;
}
