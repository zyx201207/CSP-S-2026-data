//GZ-J00499 贵阳市南明区华麟学校 陈锦江
#include<bits/stdc++.h>
using namespace std;
long long sum,ans,pre[int(2e5+10086)];
struct node {
	long long num;
	char ch;
} a[int(2e5+10086)],b[int(2e5+10086)],c[int(2e5+10086)];

int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,id,l,r;
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i].num>>a[i].ch;
		sum+=a[i].num;
	}
	for(int i=1; i<=n; i++) {
		pre[i]=pre[i-1]+a[i].num;
		if(pre[i]==sum/2) {
			for(int j=1; j<=i; j++) {
				b[j].num=a[j].num;
				b[j].ch=a[j].ch;
			}
			for(int j=i+1; j<=n; j++) {
				c[j].num=a[j].num;
				c[j].ch=a[j].ch;
			}
			if(sum%2==1) {
				c[i+1].num--;
			}
			l=1,r=n;
			id=i;
			break;
		}
		if(pre[i]>sum/2) {
			for(int j=1; j<=i-1; j++) {
				b[j].num=a[j].num;
				b[j].ch=a[j].ch;
			}
			b[i].num=a[i].num-(pre[i]-sum/2);
			c[i+1].num=pre[i]-sum/2;
			if(sum%2==1) {
				c[i+1].num--;
			}
			for(int j=i+2; j<=n+1; j++) {
				c[j].num=a[j-1].num;
				c[j].ch=a[j-1].ch;
			}
			l=1,r=n+1,id=i+1;
			break;
		}
	}
	while(l<r&&l<=id&&r>=id) {
		if(b[l].ch==c[r].ch) {
			if(b[l].num>c[r].num) {
				b[l].num-=c[r].num;
				r--;

			} else if(b[l].num<c[r].num) {
				c[r].num-=b[l].num;
				l++;

			} else {
				l++;
				r--;
			}
		} else {
			if(b[l].num>c[r].num) {
				ans+=c[r].num;
				b[l].num-=c[r].num;
				r--;


			} else if(b[l].num<c[r].num) {
				ans+=b[l].num;
				c[r].num-=b[l].num;
				l++;


			} else {
				ans+=b[l].num;
				l++;
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
}

