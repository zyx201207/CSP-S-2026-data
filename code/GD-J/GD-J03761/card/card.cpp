#include <bits/stdc++.h>
using namespace std;
int a[5005],b[3005],jsq[3005];
int num[3005];
bool v[3005];
int n,m;
queue<int>q;
void clear() {
	for (int i=1;i<=m;i++) {
		num[i]=b[i];
		v[i]=0;
	}
	while (!q.empty()) q.pop();
	return;
}
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
		b[a[i]]++;
	}
	for (int i=1;i<=m;i++) {
		num[i]=b[i];
	}
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=n;j++) {
			num[a[j]]--;
			if (!v[a[j]]) {
				v[a[j]]=1;
				q.push(a[j]);
			}
			else {
				while (q.front()!=a[i]) {
					q.pop();
				} 
				q.pop();
			} 
		}
		for (int j=1;j<=m;j++) {
			if (v[a[j]]) {
				jsq[a[j]]++;
			}
		}
		clear();
	}
	for (int i=1;i<=m;i++) {
		cout<<jsq[i]<<' ';
	}
	return 0;
} 
