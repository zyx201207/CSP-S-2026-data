#include<bits/stdc++.h>
using namespace std;
const int N = 100005;
int n,m;
struct Pair{
	int a;
	long long cnt;
}b[N];
int bb1[N];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i = 0;i<n;i++){
		cin>>b[i].a;
		int u = b[i].a;
		while(u > 0){
			if(u % 2 ==1) b[i].cnt++;
			u /= 2;
		}
	}
	long long maxnn = b[0].cnt;
	for(int j = 0;j<m;j++){
		for(int i = 1; i<n;i++){
			maxnn = max(b[i].cnt,maxnn);
		}	
		bb1[j] = maxnn;
	}
	long long maxn = bb1[0];
	for(int j = 1;j < m;j++){
		maxn &= bb1[j];
		cout<<maxn<<endl;
	}
	cout<<maxn;
	return 0;
}
