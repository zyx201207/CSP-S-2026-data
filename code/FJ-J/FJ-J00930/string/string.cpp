#include<bits/stdc++.h>
using namespace std;

int n;
const int N=2e5+5;
struct Node{
	long long t;
	char c;
}a[N];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	int cnt=0;
	long long temp;
	char tempc;
	for(int i=1;i<=n;i++){
		scanf("%lld%c%c",&temp,&tempc,&tempc);
		if(a[cnt].c==tempc) a[cnt].t+=temp;
		else{
			a[++cnt].c=tempc;
			a[cnt].t=temp;
		}
		scanf("%c",&tempc);
	}
	
	if(cnt==1){
		cout<<0;
		return 0;
	} 
	
	int i=1,j=cnt;
	long long ans=0;
	while(i<=j){
		long long sum=min(a[i].t,a[j].t);
		if(a[i].c!=a[j].c) ans+=sum;
		a[i].t-=sum;
		a[j].t-=sum;
		if(a[i].t<=0) i++;
		if(a[j].t<=0) j--;
	}
	
	cout<<ans;
	return 0;
}

