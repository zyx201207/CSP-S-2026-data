#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m;
long long a[N];
queue<int> q;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>a[i];
	int p=1;
	p<<31;
	for(int i=1;i<=n;++i){
		int sum=0;
		while(p!=0){
			if(a[i]&p!=0){
				sum++;
				p>>1;
			}
		}
		q.push(sum);
		sum=0;
	}
	return 0;
}
