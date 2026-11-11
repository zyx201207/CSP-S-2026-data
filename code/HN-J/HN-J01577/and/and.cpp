#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e5+10;
ll a[N],n,m,y[N];
ll x[41];
string s[N];
ll cnt=-1;
bool cmp(string x,string y){
	return x>y;
}
bool cmp1(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		y[i]=a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=31;j>=0;j--){
			if(a[i]-pow(2,j)>=0){
				a[i]-=pow(2,j);
				s[i]+='1';
			}else{
				s[i]+='0';
			}
		}
	}
	sort(s+1,s+1+n,cmp);
	sort(y+1,y+1+n,cmp1);
	for(int i=1;i<=n;i++){
		string h=s[i];
		for(int j=0;j<32;j++){
			if(h[j]=='1')x[j]++;
		}
	}
	for(int i=0;i<32;i++){
		if(x[i]>=m){
			int r=1;
			for(int j=1;j<=n;j++){
				string h=s[j];
				if(h[i]=='1'&&r<=m){
					if(cnt==-1){
						cnt=y[j];
						r++;
						continue;
					}else{
						cnt=(cnt & y[j]);
					}
					r++;
				}
			}
			break;
		}	
	}
	cout<<cnt<<'\n';
	return 0;
}

