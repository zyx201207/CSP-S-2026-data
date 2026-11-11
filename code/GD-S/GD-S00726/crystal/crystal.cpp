#include<bits/stdc++.h>

using namespace std;

#define cin fin
#define cout fout

using ll=long long;

const int N=5e5+9;

ll n,m,a[N];
int ans=1;

int main(){
	ifstream fin("crystal.in");
	ofstream fout("crystal.out");
	
	cin>>n>>m;
	ll d=m;
	for(int i=1;i<=n;++i) cin>>a[i];
	sort(a+1,a+1+n);
	int p=n;
	for(int i=n;i>=1;--i){
	//cout<<"!!!!!!!!!!!";
		while(p>=1){
			ll cha=a[i]-a[p];
			if(d>=cha){
				d-=cha;
				--p;
				ans=max(ans,i-p);
			}
			else break;
		}
		if(p<1) break;
		d+=(a[i]-a[i-1])*(i-p);
	}
	cout<<ans;
	fin.close();
	fout.close();
	return 0;
}
