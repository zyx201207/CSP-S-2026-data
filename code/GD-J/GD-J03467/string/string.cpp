#include<bits/stdc++.h>
using namespace std;

const int N=2e5+10;
struct Node {
	long long x;
	char s;
}a[N];
string s2;
long long n,t,y;
long long ans,cnt;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>a[i].x>>a[i].s;
        ans+=a[i].x;		
	}
////	y=ans/2;
////	for(int i=1;i<=n;i++) {
////		t+=a[i].x;
////		if(t>y) {
////			s2=a[i].s;
////			break;
////		}
////	}
	long long i=1,j=n;
	while(i<j) {
		if(a[i].s!=a[j].s) {
			if(a[i].x<a[j].x) {
				cnt+=a[i].x;
				a[j].x-=a[i].x;
				i++;
			}
			else if(a[i].x>a[j].x){
				cnt+=a[j].x;
				a[i].x-=a[j].x;
				j--;
			}
			else {
				cnt+=a[i].x;
				i++;
				j--;
			}
		}
		else {
			if(a[i].x<a[j].x) {
				a[j].x-=a[i].x;
				i++;
			}
			else if(a[i].x>a[j].x) {
				a[i].x-=a[j].x;
				j--;
			}
			else {
				i++;
				j--;
			}
		}
	}
	cout<<cnt;
	return 0;
}
