#include"bits/stdc++.h"
using namespace std;
#define ll long long
const int MAXX=5*1e5+1;
ll n,m,a[MAXX],js[MAXX];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	ll fb=m,jl=1;
	bool cha=1;
	bool shi=1;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
		if(i>=3){if(a[i]==a[i-1]&&a[i-1]==a[i-2] && cha==1)cha=1;else cha=0;}
		if( i >1&&i==a[i] && i-1==a[i-1] && shi==1)shi=1;
		else shi=0;
		if(a[i]<m){
			js[jl]=(m-a[i]);
			jl++;
		}
	}
	if(cha==1){
		int sum = 1;
		int cc=a[2]-a[1];
		while(m > cc){
			if(m > (2*cc)){
				m-=(2*cc);
				cc*=2;
				sum+=2;
			}
			else {
				sum++;
				break;
			}
		}
		cout<<sum;
		return 0;
	}
	if(shi==1){
		cout<<m+1;
		return 0;
	}
	sort(js+1,js+jl+1);
	ll i=1,sum=0;
	while(fb>0 && i<=jl){
		if(fb>=js[i]){
			sum++;
			fb-=js[i];
			i++;
		}
		else break;
	}
	cout<<(m+sum-2)/(sum-1);
	//cout<<(m+sum-2)/((m+sum-2)/(sum-1))+1;
	//cout<<m+sum-2<<endl<<sum-1;
	//cout<<sum;
}
