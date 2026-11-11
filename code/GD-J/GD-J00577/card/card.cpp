#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	vector<long long> x(n),y(m+1,0);
	vector<stack<int>> a(n);
	for(int i=0; i<n; i++) {
		cin>>x[i];
	}
//	for(int i=0; i<n; i++) {
//		cout<<x[i];
//	}
	for(int i=0; i<n; i++) {
//		cout<<1111111;
		vector<long long> ls(m+1);
		for(int j=i; j<n; j++) {
			if(ls[x[j]]>0) {
				while(a[i].top()!=x[j]) {
					ls[a[i].top()]--;
					y[a[i].top()]--;
//					cout<<a[i].top()<<endl;
					a[i].pop();



//					for(int i=1; i<=m; i++) {
//						cout<<y[i]<<" ";
//					}
//					cout<<endl;


				}
//				cout<<"ajskflajfl";
				ls[a[i].top()]--;
				y[a[i].top()]--;
//				cout<<"yyyyyyyyyyyyyyyy";
//				cout<<a[i].top()<<endl;
				a[i].pop();
//				for(int i=1; i<=m; i++) {
//					cout<<y[i]<<" ";
//				}
//				cout<<endl;
			}
			a[i].push(x[j]);
			ls[a[i].top()]++;
			y[a[i].top()]++;
//			cout<<a[i].top()<<endl;
//			for(int i=1; i<=m; i++) {
//				cout<<y[i]<<" ";
//			}
//			cout<<endl;
		}
	}
	for(int i=1; i<=m; i++) {
		cout<<y[i]<<" ";
	}
//	stack<int> a;
//	a.push(1);
//	cout<<a.top();
}
