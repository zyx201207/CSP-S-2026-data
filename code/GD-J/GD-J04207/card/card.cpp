#include<bits/stdc++.h>
using namespace std;
long long n,m,a[9000000],wait[9000000],s,o,co[9000000],fi;
bool af(long long w) {
	for(int i=0; i<n; i++) {
		if(wait[i]==w) {
			fi=i;
			return 1;
		}
	}
	return 0;
}
void clean() {
	for(int i=fi; i<o; i++) {
		wait[i]=0;
	}
	o=fi;
}
void bigclean() {
	for(int i=0; i<o; i++) {
		wait[i]=0;
	}
	o=0;
}
void put() {
	for(int i=0; i<o; i++) {
		if(wait[i]!=0) {
			co[wait[i]]++;
		}
	}
}
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0; i<n; i++) {
		cin>>s;
		a[i]=s;
	}
	for(int game=1; game<=n; game++) {
		for(int i=game-1; i<n; i++) {
			if(!af(a[i])) {
				wait[o]+=a[i];
				o++;
			} else {
				clean();
				wait[o]+=a[i];
				o++;
			}
		}
		put();
//	cout<<endl;//
		bigclean();
	}
	for(int i=1; i<=m; i++) {
		cout<<co[i]<<' ';
	}
}
