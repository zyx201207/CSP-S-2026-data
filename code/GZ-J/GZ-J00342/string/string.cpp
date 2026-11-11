//遵义汇川区周林 陈俊洁 GZ-J00342
#include <bits/stdc++.h>
using namespace std;
struct zf {
	long long id;
	char a;
} t[200005];
long long n;
long long sum=0;
long long ans=0;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1; i<=n; i++) {
		cin>>t[i].id>>t[i].a;
	}
	long long i=1,j=n;
	while(i<=j) {
		if(t[i].a!=t[j].a) {
			if(t[i].id==t[j].id) {
				ans+=t[i].id;
				i++;
				j--;
			} else {
				if(t[i].id>t[j].id) {
					t[i].id-=t[j].id;
					ans+=t[j].id;
					j--;
				} else {
					t[j].id-=t[i].id;
					ans+=t[i].id;
					i++;
				}
			}
		} else {
			if(t[i].id==t[j].id) {
				i++;
				j--;
			} else {
				if(t[i].id>t[j].id) {
					t[i].id-=t[j].id;
					j--;
				} else {
					t[j].id-=t[i].id;
					i++;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}

