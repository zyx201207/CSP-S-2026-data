#include<bits/stdc++.h>
using namespace std;
long long n,cnt,aaa,cn;
long long mid,midw,nu;
long long a,c,bn;
struct z{
	long long num;
	char m;
}b[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>b[i].num>>b[i].m;
		cnt+=b[i].num;
	}
	for(int i=1;i<n;i++){
		if(b[i].m!=b[i+1].m);
		aaa++;
	}
	if(aaa==0){
		cout<<0;
		return 0;
	}
	cn=cnt;
	for(int i=1;i<=n;i++){
		nu+=b[i].num;
		if(nu>=cnt/2){
				mid=i;
				midw=b[i].num-nu+cnt/2;
		}
	}
	while(a<mid&&c+1<mid){
		if(b[a].m==b[n-c].m){
			if(b[a].num>b[n-c].num){
				b[a].num-=b[n-c].num;
				cnt-=b[n-c].num*2;
				c++;
			}
			else if(b[a].num<b[n-c].num){
				b[n-c].num-=b[a].num;
				cnt-=b[a].num*2;
				a++;
			}
			else if(b[a].num==b[n-c].num){
				cnt-=b[a].num;
				cnt-=b[n-c].num;
				c++;
				a++;
			}
		}
		else if(b[a].m!=b[n-c].m){
			if(b[a].num>b[n-c].num){
				b[a].num-=b[n-c].num;
				c++;
			}
			else if(b[a].num<b[n-c].num){
				b[n-c].num-=b[a].num;
				a++;
			}
			else if(b[a].num==b[n-c].num){
				c++;
				a++;
			}
		
		}
	}
	if(c==mid&&a<mid){
		if(cn%2==0){
			b[c].num-=2*midw;
		}
	}
	else if(c<mid&&a==mid){
		if(cn%2==0){
			b[a].num-=2*(b[a].num-midw);
		}
	}if(c==a){
		cnt-=b[a].num;
		
	}
	else if(b[a].m==b[c].m){
		cnt-=b[a].num;
		cnt-=b[c].num;
	}
	cout<<cnt;
	return 0;
}
