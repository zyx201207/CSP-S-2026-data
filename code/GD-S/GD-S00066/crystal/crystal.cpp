#include<bits/stdc++.h>
using namespace std;

long long n;
long long m;
long long ma;

struct Node{
	long long e;
	long long c;
}a[500001];

bool bmp(Node x,Node y){
	if(x.c>=y.c) return true;
	return false;
}

void w(){
	for(int i=1;i<=n;i++){
		cin>>a[i].e;
	}
	
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=n;j++){
			a[j].c=a[i].e-a[j].e;
		}
		sort(a+1,a+n,bmp);
		long long u=m;
		long long cnt=0;
		for(long long j=1;j<=n;j++){
			if(u-a[j].c>=0 && a[j].c>=0){
				u-=a[j].c;
				cnt++;
			}
			else break;
		}
		ma=max(cnt,ma);
	}
	
	cout<<ma;
	
	return;
}

long long r;
long long h;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin>>n>>m;
	
	//特殊性质 
	if(m>=100000000000000000){
		for(int i=1;i<=n;i++){
			cin>>a[i].e;
		}
		
		long long q=a[2].e-a[1].e;
		
		for(int i=1;i<=n;i++){
			if(r+i*q<=m){
				r+=i*q;
				h++;
			}
		}
		
		cout<<h;
	}
	
	//一般性质 
	else{
		w();
	}
	
	return 0;
} 
