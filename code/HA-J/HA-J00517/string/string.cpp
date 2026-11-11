#include<bits/stdc++.h>
using namespace std;
string s;
long long n,a[200005],l,h,t;
long long sum;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	char c[200005];
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	h=1,t=n;
	while(h!=t){
		if(c[h]!=c[t]){
			if(a[h]>a[t]){
				c[t]=c[h];
				sum+=a[t];
				a[h]-=a[t];
				t--;
				
			}
			else{
				c[h]=c[t];
				sum+=a[h];
				a[t]-=a[h];
				h++;
				
			}
		}
		else{
			if(a[h]>a[t]){
				a[h]-=a[t];
				t--;
				
			}
			else{
				a[t]-=a[h];
				h++;
				
			}
		}
	}
	cout<<sum;
	return 0;
}
