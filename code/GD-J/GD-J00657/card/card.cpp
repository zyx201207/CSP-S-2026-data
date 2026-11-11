#include<bits/stdc++.h> 
using namespace std;
long long n,m,c[500005],t[500005],lt=0,lm=0,cnt[500005];
bool b1=0;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int k=1;k<=n;k++){
		lt=0;
		for(long long i=k;i<=n;i++){
			lm=0;
			b1=0;
			long long l=c[i];
			for(long long j=1;j<=lt;j++){
				if(t[j]==l&&b1==0){
					b1=1;
				}
				if(b1){
					t[j]=0;
					lm++;
				}
			}
			lt-=lm;
			lt++;
			t[lt]=l;
		}
		for(long long j=1;j<=lt;j++) cnt[t[j]]++;
		memset(t,0,lt);
		//Trick||Treat!
	}
	for(long long i=1;i<=m;i++) cout<<cnt[i]<<' ';
	return 0;
}
