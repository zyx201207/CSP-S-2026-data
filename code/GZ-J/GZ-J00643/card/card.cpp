//GZ-J00643 个人报名 周晨诚
#include<bits/stdc++.h>
using namespace std;
int a[500005],b[300005] = {0},z = 0;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	for(int i=0;i<n;i++){
		vector<int> c;
		for(int k=i;k<n;k++){
			c.push_back(a[k]);
			if(k == i) continue;
		}
		for(int j=1;j<=m;j++){
			for(int k=0;k<c.size();k++){
				if(c[k] == j ){
					b[j]++;
				}
			}
		}
	}
	for(int j = 1;j<=m;j++){
		cout << b[j] << " ";
	}
	return 0;
} 
