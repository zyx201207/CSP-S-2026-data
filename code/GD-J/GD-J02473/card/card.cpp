#include <iostream>
#include <cstdio>
using namespace std;
int n,m;
int d[500005],p[300005];
void put(int a) {
	int i=1;
	while(d[i] != 0) {
		if(d[i]==a)  {
			i++;
			while(d[i] != 0) {
				for(int j=1;j<=n;j++) {
					if(p[j] == d[j]) {
						p[j] = 0;
						int k=j;
						while(p[k+1] != 0) {
							p[k] = p[k+1];
						}
						p[k] = 0;
					}
				}
				d[i] = 0;
				i++;
			}
			return;
		}
		i++;
	}
	d[i] = a;
}
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	for(int i=1;i<=n;i++) {
		cin >> p[i];
	}
	for(int i=1;i<=n;i++) {
		for(int j=i;j<=n;j++) {
			if(p[j]) put(p[j]);
		}
	}
	int i=1;
	put(1);
	put(1);
	while(i<=10) {
		cout << d[i] << " ";
		i++;
	}
	return 0;
}

