#include<bits/stdc++.h>
using namespace std;
int main() {
	vector<long long>x(100000000);
	vector<long long>a(100000000);
	vector<char>b(100000000);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,num,ans=0,p;
	double sum;
	char t,r;
	bool cnt=true;
	char c;
	cin>>n;
	vector<long long>l(n);
	for(int i=0; i<n; i++) {
		cin>>num>>t;
		if(i==0)c=t;
		a[i]=num;
		b[i]=t;
		sum+=num;
		x[i]=sum;
		l[t-'a']+=num;
		if(t!=c) {
			cnt=false;
		}
		//cout<<x[i]<<" ";
	}
	if(cnt==false) {
		if(a[0]>=sum/2.0) {
			cout<<sum-a[0];
		} else if(a[0]<sum/2.0) {
			//cout<<"666"<<endl;
			if(a[0]==a[n-1]) {
				cout<<a[0];
			} else {
				for(int i=0; i<n; i++) {
					if(x[i]>=sum/2.0&&x[i-1]<=sum/2.0) {
						r=b[i];
						p=x[i]-1;
					}
				}
				cout<<r<<"	"<<p<<endl;
				if(sum/2.0<p) {
					cout<<sum/2.0-(p-sum/2.0);
				} else if(sum/2.0==p) {
					cout<<sum/2.0;
				}
			}
		}
	} else {
		cout<<"0";
	}
	return 0;
}
