#include<bits/stdc++.h>
using namespace std;
vector<int> A;
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0; i<n; i++) {
		int a;
		cin>>a;
		A.push_back(a);
	}
	int d=(int)n/2;
	int b=A[d];
	for(int i=0; i<n; i++) {
		if(b==A[i] && d<i) {
			d=i;
		}
	}
	cout<<d+1;
	return 0;
}

/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/

//Oct31==Dec25?
