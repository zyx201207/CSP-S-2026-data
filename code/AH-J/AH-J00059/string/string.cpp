#include <bits/stdc++.h>
using namespace std;
long long n,a[1000000],b=0,e=0;
char c[1000000];
string d;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>c[i];
		for(int j=b;j<b+a[i];j++){
			d[j]=c[i];
		}
		b+=a[i];
	}
	long long i=0,j=b-1;
	while(i<=j){
		if(d[i]!=d[j]){
			e++;
		}
		i++;
		j--;
	}
	cout<<e;
	return 0;
}
