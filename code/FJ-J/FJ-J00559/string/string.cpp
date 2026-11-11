#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long n,y,sum,a[N];
char c[N];
string s;
bool x=1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		if(i>1){
			if(c[i]==c[i-1]){
				a[i-1]=a[i-1]+a[i];
				i--;
				n--;
			}else{
				x=0;
			}
		}
	}
	if(x){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		sum=sum+a[i]/2;
	}
	cout<<sum;
	return 0;
}
