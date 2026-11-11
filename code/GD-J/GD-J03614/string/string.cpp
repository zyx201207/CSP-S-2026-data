#include<iostream>
using namespace std;
long long a[10000005];
string d,j;
int main() {
	ios::sync_with_stdio;
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	long long n,b,cnt=0,sum=1,l=0,count=0,num=0;
	char c;
	cin>>n;
	for(long long i=1; i<=n; i++) {
		cin>>b>>c;
		cnt+=b;
		d[sum]=c;
		sum++;
	}
	for(long long i=1; i<=n; i++) {
		if(d[i]==d[i+1]) {
			l++;
		}
	}
	if(l==n-1) {
		cout<<"0";
		return 0;
	}
	sum=1;
	int p=0;
	long long nu2=0,nu3=0,o=1;
			if(cnt%2==0) {
				cout<<cnt/2+1-count;
				return 0;
			} else {
				cout<<cnt/2-count;
				return 0;
			}
	return 0;
}
