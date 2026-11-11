#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=2e5+5;
ll n,l=1,r,sum,a[M][3];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i][1]>>s;
		a[i][2]=s[0];
	}
	r=n;
	while(l<r){
		if(a[l][1]>a[r][1]){
			if(a[l][2]!=a[r][2]){
				sum+=a[r][1];
			}
			a[l][1]-=a[r][1];
			r--;
		}else if(a[l][1]<a[r][1]){
			if(a[l][2]!=a[r][2]){
				sum+=a[l][1];
			}
			a[r][1]-=a[l][1];
			l++;
		}else{
			if(a[l][2]!=a[r][2]){
				sum+=a[l][1];
			}
			l++,r--;
		}
	}
	cout<<sum;
	return 0;
} 

