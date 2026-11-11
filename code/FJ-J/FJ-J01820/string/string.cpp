#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int t,k,l=1,h;
long long beginn[N],endd[N];
char d[N];
long long cnt,n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>t;
	h=t;
	for(int i=1;i<=t;i++){
		int c;
		cin>>c>>d[i];
		beginn[i]=endd[i-1];
		endd[i]=beginn[i]+c;
	}
	n=endd[t];
	for(int i=0;i<n/2;i++){
		if(i>=beginn[l+1]){
			l++;
		}
		if(n-i-1<endd[h-1]){
			h--;
		}
		if(d[l]!=d[h]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
