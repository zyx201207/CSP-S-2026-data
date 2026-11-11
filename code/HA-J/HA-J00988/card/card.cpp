#include<bits/stdc++.h>
using namespace std;
unsigned long long a,m,n,b[10000005],c[10000005],e[10000005],x,y;
bool t=0;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>m>>n;
	for(unsigned long long i=1;i<=m;i++){
		cin>>b[i];
	}
	unsigned long long l[n+100000];
	for(unsigned long long i=1;i<=m;i++){
		memset(c,0,sizeof(c));
		for(unsigned long long j=i;j<=m;j++){
			for(unsigned long long z=1;z<=j;z++){
				if(c[z]==b[j]){
					t=1;
				}
				if(t==1){
					c[z]=0;
				}
			}
			t=0;
			c[j]=b[j];
		}
		sort(c,c+m+1);
		reverse(c,c+m+1);
		for(unsigned long long p=1;p<=n;p++){
			if(c[p]==n-i+1){
				l[p]++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		cout<<l[i]<<' ';
	}
	return 0;
}
	
