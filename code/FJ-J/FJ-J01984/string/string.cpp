#include<bits/stdc++.h>
using namespace std;
struct zfc {
	int sl;
	char zf;
} num[200005];
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	int n;
	cin>>n;
	bool f=0;
	for(int i=1; i<=n; i++) {
		cin>>num[i].sl>>num[i].zf;
	}
	int m=n;
	long long sum=0;
	for(int i=1; i<=n/2; i++) {
		if(num[i].zf!=num[m].zf) {
			if(num[i].sl>=num[m].sl) {
				sum+=num[i].sl;
				num[m-1].sl=num[m-1].sl-num[i].sl+num[m].sl;
			}
			else {
				sum+=num[i].sl;
				num[i+1].sl=num[i+1].sl-num[m].sl+num[i].sl;
			}
		}
		m--;
	}
	cout<<sum;
	return 0;
}

