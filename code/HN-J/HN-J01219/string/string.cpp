#include<bits/stdc++.h>;
using namespace std;
long long int n,c,cnt;
char b,a[100000000+5];
int main() {
	freopen("string1.in","r",stdin);
	freopen("string1.out","w",stdout);
	cin>>n;
	long long int heat,low;
	for(int i=1; i<=n; i++) {
		heat+=c;
		cin>>c>>b;
		low+=c;
		if(i==1) {
			heat=1;
			low=c;
		}
		for(int j=heat; j<=low; j++) {
			a[j]=b;
		}
	}
	if(low%2==0) {
		for(int i=1; i<=low;) {
			if(a[i]!=a[low]) {
				low--;
				i++;
				cnt++;
			} else {
				low--;
				i++;
			}
		}
	} else {
		for(int i=1; i<=low;) {
			if(low==i) {
				break ;
			}
			if(a[i]!=a[low]) {
				low--;
				i++;
				cnt++;
			}


			else {
				low--;
				i++;
			}
		}

	}
	cout<<cnt;
	return 0;
}
