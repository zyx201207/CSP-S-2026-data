#include<bits/stdc++.h>
#include<vector>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long n,m;
	cin>>n>>m;
	vector<long long>a(n),suf(n+1),pix(n+1);
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a.begin(),a.end());
	suf[0]=0,suf[1]=0;
	for(long long i=1;i<n;i++){
		suf[i+1]=a[i]-a[i-1];
		pix[i+1]=pix[i]+suf[i+1];
	}
	long long cost=0;
	long long l=1,r=0,len=0,maxlen=0;
	while(1){
		if(len*suf[r+1]+cost<=m){
			cost+=len*suf[r+1];
			r++;
			len++;
			maxlen=max(maxlen,len);if(r==n)break;
			continue;
		}
		if(r==n)break;
		cost=cost-(pix[r]-pix[l]);
		l++;
		len--;
	}
	cout<<maxlen<<endl;
	return 0; 
}
