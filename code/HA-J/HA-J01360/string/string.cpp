#include<bits/stdc++.h>
using namespace std;
int n,k1[500005],p=-1,z,y;
long long l;
char k2[500005];
string a;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>k1[i]>>k2[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=p+1;j<=k1[i]+p;j++){
			a[j]=k2[i];
		}
		p+=k1[i];
	}
	p++;
		for(int i=0;i<=p/2-1;i++){
			if(a[i]!=a[p-i-1]){
			l++;	
			}
		}
		cout<<l;

	return 0;
}
