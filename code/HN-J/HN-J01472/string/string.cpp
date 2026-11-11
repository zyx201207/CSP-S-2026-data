#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a[200010]= {},all=0;
	char w[200010]= {};
	cin>>n;
	for(long long i=1; i<=n; i++) {
		cin>>a[i]>>w[i];
	}
	if(n<=2000) {
		if(n<=2) {
			if(w[1]==w[2])cout<<"0";
			else cout<<min(a[1],a[2]);
		} else {
			string b;
			for(int i=1; i<=n; i++) {
				for(int c=1; c<=a[i]; c++) {
					b+=w[i];
				}
			}
			if(b.size()%2==0) {
				for(int i=0; i<b.size(); i++) {
					if(b[i]!=b[b.size()-1]) {
						all++;
					}
					if(i+1==b.size()/2) {
						cout<<all;
						break;
					}
				}
			}else  {
				for(int i=0; i<b.size(); i++) {
					if(i==(b.size()-1)/2) {
						cout<<all;
						break;
					}
					if(b[i]!=b[b.size()-1]) {
						all++;
					}
				}
			}


		}

	} else if(n%2==0) {
		for(long long i=1; i<=n; i++ ) {
			if(i==n-i) {
				cout<<all;
				break;
			}
			if(a[i]==a[n-i+1]) {
				if(w[i]!=w[n-i+1])all+=a[i];
			} else if(a[i]>a[n-i+1]) {
				if(w[i]!=w[n-i+1]) {
					all+=a[i];
					a[n-i]-=a[i]-a[n-i+1];
				} else {
					all+=a[n-i+1]-a[i];
					a[i+1]-=a[n-i+1]-a[i];
				}
			} else if(a[i]<a[n-i+1]) {
				if(w[i]!=w[n-i+1]) {
					all+=a[n-i+1];
					a[i+1]-=a[n-i+1]-a[i];
				} else {
					all+=a[i]-a[n-i+1];
					a[i+1]-=a[i]-a[n-i+1];
				}
			}
		}
	} else if(n%2!=0) {
		for(long long i=1; i<=n; i++ ) {
			if(i==n-i+1) {
				cout<<all;
				break;
			}
			if(a[i]==a[n-i+1]) {
				if(w[i]!=w[n-i+1])all+=a[i];
			} else if(a[i]>a[n-i+1]) {
				if(w[i]!=w[n-i+1]) {
					all+=a[i];
					a[n-i]-=a[i]-a[n-i+1];
				} else {
					a[i+1];
				}
			} else if(a[i]<a[n-i+1]) {
				if(w[i]!=w[n-i+1]) {
					all+=a[n-i+1];
					a[n-i]-=a[n-i+1]-a[i];
				}
			}
		}
	}

	return 0;
}
