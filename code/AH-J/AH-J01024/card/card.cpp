#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[300005],c[300005];
stack<long long> s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n-1;i++){
		for(int j=i;j<=n;j++){
			if(b[a[j]]==0){
				s.push(a[j]);
				b[a[j]]++;
			}
			else{
				while(b[a[j]]!=0){
					long long qq=s.top();
					s.pop();
					b[qq]--;
				}
				s.push(a[j]);
				b[a[j]]++;
			}
		}
		while(!s.empty()){
			long long pp=s.top();
			c[pp]++;
			b[pp]--;
			s.pop();
		}
	}
	c[a[n]]++;
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
} 
