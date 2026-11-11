#include<bits/stdc++.h>
using namespace std;
int n,m,b;
string t;
int a[1000000],zhong[1000000];
void check(int asd) {
	int aqw=t.find(asd);
	if(aqw>0) {
		while(aqw<n) {
			t[aqw]=' ';
			aqw++;
		}
	}

}
int main() {
//	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0; i<n; i++) {
		scanf("%d",&a[i]);
	}
	for(int i=0; i<n; i++) {
		b+=i;
		while(a[b]!=0) {
			t+=a[b];
			check(a[b]);
			b++;
		}
		b=0;
		for(int j=0; j<t.size(); j++) {
			cout<<t[i];

		}
	}
	t=' ';

	for(int i=0; i<m; i++) {
		cout<<zhong[i]<<" ";
	}
}

//全忘了，气死我了
