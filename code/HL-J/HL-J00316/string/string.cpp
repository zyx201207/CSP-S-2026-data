#include<bits/stdc++.h>

using namespace std;
#define int long long

const int N= 2e5+1;
int a[N],n;
char b[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin >>a[i]>>b[i];
		//cout <<"wop";
	}
	int l = 1,r = n,ls = a[1],rs = a[n];
	int ans = 0;
	//cout <<") "<<n<<endl;;
	while(l < r){
		//cout <<"(";
		if(b[l]==b[r]){
			if(ls>rs){
				ls-=rs;
				r--;
				rs = a[r];
			}
			else if(ls < rs){
				rs -= ls;
				l++;
				ls = a[l];
			}
			else if(ls==rs){
				l++,r--;
				ls =a[l];rs = a[r];
			}
		}
		else{
			//cout <<"*";
			if(ls > rs){
				r--;
				ls-=rs;
				ans+=rs;
				rs = a[r];
			}
			else if(rs > ls){
				l++;
				rs-=ls;
				ans+=ls;
				ls = a[l];
			}
			else{
				ans+=ls;
				l++;r--;
				ls=a[l];rs=a[r];
			}
		}
		
	}
	cout <<ans;
	return 0;
}
