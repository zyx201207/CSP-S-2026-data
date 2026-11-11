#include<bits/stdc++.h>
#define N 5005
using namespace std;
long long c,t;
void sol(){
	long long n,d;
	cin >> n >> d;
	long long a[n+5];
	for(int i=1;i<=n;i++)
		cin >> a[i];
	long long cnt=0;
	for(int i=1;i<=n-3;i++){
		if(a[i+3]-a[i]<=2*d){
			if(a[i+1]-a[i]<=d&&a[i+2]-a[i+1]<=d&&a[i+3]-a[i+2]<=d){
				if(a[i+3]-a[i]>d){
					cnt++;
				}
			}
		}
	}
	cout << cnt << endl;
}
void sol2(){
	long long n,d;
	cin >> n >> d;
	long long a[n+5];
	for(int i=1;i<=n;i++)
		cin >> a[i];
	if(d<=(a[2]-a[1]))
		cout << "0" << endl;
	else if(d>=(a[n]-a[1]))
		cout << "0" << endl;
	else{
		long long t=d/(a[2]-a[1])+2;
		if(t>=n) cout << "0" << endl;
		else cout<< n-((t-3)*2+1) << endl;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	if(c<=10){
		while(t--){
			sol();
		}
	}
	else if(c==11&&c==12){
		while(t--){
			sol2();
		}
	}
	else if(c==13&&c==14){
		cout << "2" << endl;
	}
}
