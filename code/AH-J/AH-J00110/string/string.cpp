#include<bits/stdc++.h>
using namespace std;
long long n,tmp=1,nnum,ans;
struct node{
	long long num;
	char c;
}a[200010],b[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i].num>>a[i].c;
	b[1].c=a[1].c,b[1].num=a[1].num;
	for(int i=2;i<=n;i++){
		if(a[i].c==a[i-1].c)b[tmp].num+=a[i].num;
		else{
			++tmp;
			b[tmp].num=a[i].num;
			b[tmp].c=a[i].c;
		}
	}
	long long l=1,r=tmp;
	while(l<=r){
		if(b[l].c==b[r].c){
			if(b[l].num<b[r].num){
				b[r].num-=b[l].num;
				l++;
				continue;
			}
			if(b[l].num==b[r].num){
				l++;
				r--;
				continue;
			}
			if(b[l].num>b[r].num){
				b[l].num-=b[r].num;
				r--;
				continue;
			}
		}
		if(b[l].c!=b[r].c){
			if(b[l].num<b[r].num){
				b[r].num-=b[l].num;
				ans+=b[l].num;
				l++;
				continue;
			}
			if(b[l].num==b[r].num){
				ans+=b[l].num;
				l++;
				r--;
				continue;
			}
			if(b[l].num>b[r].num){
				ans+=b[r].num;
				b[l].num-=b[r].num;
				r--;
				continue;
			}
		}
	}
	cout<<ans;
	return 0;
}
