#include<bits/stdc++.h>
using namespace std;
int n;
struct node {
	long long cnt;
	char c;
};
node a[200050];

long long ans;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i].cnt>>a[i].c;
	}
	bool f=0;
	if(n%2==0) f=1;
	for(int i=1,j=n; i!=j;) {
	//	if(f==0&&abs(i-j)==1) break;
		long long k=a[i].cnt-a[j].cnt;
		if(a[i].c==a[j].c) {
			if(k>0) {
			//	a[j].cnt=0;
				a[i].cnt-=a[j].cnt;
				j--;
			} else if(k<0) {
			
			//	a[i].cnt=0;
				a[j].cnt-=a[i].cnt;
				i++;
			} else if(k==0) {
				a[j].cnt=a[i].cnt=0;
				i++,j++;
			}
		} else {
			if(k>0) {
				a[i].cnt-=a[j].cnt;
			
				ans+=a[j].cnt;
			//	cout<<j<<" "<<a[i].c<<endl;
					a[j].cnt=0;
				j--;
			} else if(k<0) {
				a[j].cnt-=a[i].cnt;
				ans+=a[i].cnt;
			//	cout<<i<<" "<<a[j].c<<endl;
				a[i].cnt=0;
				i++;
			} else if(k==0) {
				ans+=a[i].cnt;
				a[i].cnt=a[j].cnt=0;	
			//	cout<<i<<" "<<a[j].c<<endl;
				i++,j--;
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		cout<<a[i].cnt<<" "<<a[i].c<<endl;;
//	}
	cout<<ans;
	return 0;
}
