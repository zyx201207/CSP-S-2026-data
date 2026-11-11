#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	//ios::sycn_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	long long n,a,k=1,x=0,ans=0;
	char c;
	string b;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		while(a>=1){
			a--;
			k++;
			b[k]=c;
		}
	}
	x=k-1;
	long long y;
	y=x/2+1;
	for(long long i=y+1;i>=2;i--){
		if(b[i]!=b[x+1-i]) ans++;
	}
	cout<<ans<<endl;
	return 0;
}
