#include<bits/stdc++.h>
using namespace std;
int a[500005],sl[500005],sl1[500005];
vector<int> q;
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,h=1;
	cin>>n>>m;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
	}
	for (int i=1;i<=n;i++) {
		for (int j=i;j<=n;j++) {
			if (a[j]<=m) {
				sl1[a[j]]++;
				if (sl1[a[j]]>=2) {
					while (q.size()-1>=1&&q.back()!=a[j]) {
						sl1[q.back()]--;
						q.pop_back();
					}
					sl1[a[j]]=1;
				} else q.push_back(a[j]);
			}
		}
		for (int j=1;j<=m;j++) {
			if (sl1[j]!=0) {sl[j]++;}
			sl1[j]=0;
		}
	}
	for (int i=1;i<=m;i++) cout<<sl[i]<<" ";
	cout<<endl;
	return 0;
}
/*
4 3
1 2 1 3

10 3
3 1 2 1 3 2 3 1 2 1

×Ü¹À·Ö£º100+100+70+48=318 
*/
