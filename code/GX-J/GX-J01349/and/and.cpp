#include<bits/stdc++.h>
using namespace std;
const int re=2*1e6;
long long w[re];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int o=0;o<n;o++){
		cin>>w[o];
		}
		sort(w,w+n,greater<int>());
	long long fir=w[0];
	if(m==1){
		cout<<fir;
		return 0;
		}
	for(int e=1;e<m;e++){
		fir&=w[e];
		}
		cout<<fir;
	return 0;
	}
//miao~miao~miao~
