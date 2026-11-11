#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long x[N],sum,cnt=0,b,c;
long long n;
string a="";
char y[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>y[i];
	}
	for(int i=1;i<=n;i++){
		sum+=x[i];
		for(int j=1;j<=x[i];j++){
			a+=y[i];
		}
	}
	if(sum%2==1){
		b=sum/2;
		for(int i=0,j=a.size()-1;i<b&&j>b;i++,j--){
			if(a[i]!=a[j]){
				cnt++;
			}
		}
	}
	else{
		c=sum/2;
		for(int i=0,j=a.size()-1;i<c&&j>c-1;i++,j--){
			if(a[i]!=a[j]){
				cnt++;
			}
		}
	}
	cout<<cnt;
	return 0;
}
