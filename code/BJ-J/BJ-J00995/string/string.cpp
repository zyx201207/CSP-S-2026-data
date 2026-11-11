#include<bits/stdc++.h>
using namespace std;
const int N=200005;
long long n,sum,ans;
long long a[N];
char b[N];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		ans+=a[i];
	}
	long long x=1,y=n;
	while(x<y){
		if(b[x]!=b[y]){
			if(a[x]>a[y]){
				sum+=a[y];
				a[x]-=a[y];
				y-=1;
			}else{
				sum+=a[x];
				a[y]-=a[x];
				x+=1;
			}
		}else{
			if(a[x]>a[y]){
				a[x]-=a[y];
				y-=1;
			}else{
				a[y]-=a[x];
				x+=1;
			}
		}
	}
	cout<<sum;
	return 0;
}
