#include<bits/stdc++.h>
using namespace std;
int a[500005];
int b[500005];
int main(){
	freopen("crystal1.in","r",stdin);
	int n,m,cnt=0,tot=0,m_t=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cnt+=a[i];
	}
	cnt/=n;
	for(int i=1;i<=n;i++){
		b[i]=a[i]-cnt;
	}
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++){
		m+=b[i];
		tot++;
		if(m<0) break;	
	}

	cout<<tot;
	return 0;
}
