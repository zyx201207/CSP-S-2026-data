#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+10;
int num[N];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,maxn=0;
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>num[i];
	for(int i=0;i<n-2;i++){
		for(int j=i;j<n-2;j++){
			int a=num[i]&num[j+1];
			if(a>=maxn) maxn=a;
		}
	}
	cout<<maxn;
	return 0;
}
