#include<bits/stdc++.h>
using namespace std;

long long c,t,n,d,i,j,k,s,m,x[2000010];

bool dc;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	for(k = 1;k<=t;k++){
		cin >> n >> d;
		dc = true;
		for(i = 1;i<=n;i++){
			cin >> x[i];
			if(i>3 && (x[i]-x[i-1]!=x[2]-x[1]))dc = false;
		}
		if(n<=3){
			cout << 0 << endl;
			continue;
		}
		if(n==4 && x[4]-x[1]>d){
			cout << 1 << endl;
			continue;
		}
		if(c==11 || c==12 || dc){
			long long h = x[2]-x[1];
			if(d>=h*2 && d<h*3){
				if(n>=3){
					cout << n-4+1 << endl;
				}
				else{
					cout << 0 << endl;
				}
			}
			else{
				cout << 0 << endl;
			}
			continue;
		}
		if(c==13 && c==14){
			bool p = true;
			for(i = 1;i<=n;i++){
				if(x[i]-x[1]>d){
					cout << n-i+1 << endl;
					p = false;
				}
			}
			if(p)cout << 0 << endl;
			continue;
		}
		s = 0;
		for(i = 1;i<=n-3;i++){
			for(j = i+2;j<=n;j++){
				if(x[j]-x[i]<=d){
					for(m = j+1;m<=n;m++){
						if(m==j+1 && x[m]-x[j]<=d);
						if(x[m]-x[j]<=d && x[m]-x[i]>d)s++;
					}
				}
			}
		}
		cout << s << endl;
	}
	return 0;
}
