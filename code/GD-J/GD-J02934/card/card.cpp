#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n,m;
	cin>>n>>m;
	string a;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	long long ans[330000]={};
	for(long long i=1;i<=n;i++){
		string b;
		long long b1=1;
		for(long long j=i;j<=n;j++){
			long long tmp=b.find(a[j]);
			if(tmp==-1){
				b[b1]=a[j];
				b1++; 
			}else{
				for(long long x=tmp;x<j;x++){
					b[x]='0';
				}
				b[b1]=a[j];
				b1++;
			}
		}
		for(int j=i;j<=n;j++){
			if(b[j]=='0'){
				continue;
			}else{
				ans[b[j]-48]++;
			}
		}
	}
	for(long long i=1;i<=m;i++){
		cout<<ans[i]<<' '; 
	}
	return 0;
}
