#include<bits/stdc++.h>
#define ll long long
using namespace std;

int c[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i=0;i<n;i++){
		cin>>c[i];	
	}
	int maxn=0,r;
	for(int i=0;i<n;i++){
		r=c[i];
		for(int j=i;j<n;j++){
			if(r=c[j]) continue;
			r=r^c[j];
			//cout << c[j] << ":" << r << " ";
		}
		//cout << endl;
		maxn=max(r,maxn);
	}
	cout << maxn;
	return 0;
}
