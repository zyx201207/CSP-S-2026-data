#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N];
struct node{
	int m,t;
}b[N];
struct node1{
	int m,t;
}c[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int z,n,m,d,h;
	cin >> z >> n >> m >> d >> h;
	for (int i=1;i<=m;i++) cin >> a[i];
	int x;
	cin >> x;
	for (int i=1;i<=x;i++){
		cin >> b[i].m >> b[i].t;
	}
	int x1;
	cin >> x1;
	for (int i=1;i<=x1;i++){
		cin >> c[i].m >> c[i].t;
	}
	for (int i=1;i<=h;i++){
		int s,e;
		cin >> s >> e;
		int ok=0,ok1=0;
		int s1,e1;
		for (int i=1;i<=x;i++){
			if (b[i].m==s) ok=1,s1=i;
			if (b[i].m==e) ok1=1,e1=i;
		}
		long long sum=0;
		if (ok==1 && ok1==1){
			sum+=a[s1];
			for (int i=s1;i<=e1;i++){
				sum+=b[i].t;
			}
			sum+=a[e1];
			cout << sum;
		}
		ok=0,ok1=0;
		for (int i=1;i<=x1;i++){
			if (c[i].m==s) ok=1,s1=i;
			if (c[i].m==e) ok1=1,e1=i;
		}
		if (ok==1 && ok1==1){
			sum+=a[s1];
			for (int i=s1;i<=e1;i++){
				sum+=c[i].t;
			}
			sum+=a[e1];
			cout << sum;
		}
	}
	if (d==1 && d==0){
	}else if (d==2){
		cout << 0;
		return 0;
	}
}
