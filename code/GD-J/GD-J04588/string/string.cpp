#include<bits/stdc++.h>
using namespace std;
const long long N=2e5+10;
long long n,cnt,x[N],ans;
string s;
char y[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		x[i]=a;
		y[i]=c;
		cnt+=a;
	}
	for(long long i=1,j=n;;){
		if(i>=j)break;
		if(y[i]==y[j]){
			long long minl=min(x[i],x[j]),maxl=max(x[i],x[j]);
			if(x[j]==maxl){
				x[j]-=x[i];
			}else{
				x[i]-=x[j];
			}
			if(x[i]==minl)i++;
			if(x[j]==minl)j--;
		}else{
			long long minl=min(x[i],x[j]);
			ans+=minl;
			if(x[i]==x[j])j--;
			else if(x[i]==minl){
				x[j]-=x[i];
				i++;
			}else{
				x[i]-=x[j];
				j--;
			}
		}
	}
	cout<<ans;
	return 0;
}/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/

