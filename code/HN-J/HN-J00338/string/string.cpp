#include<bits/stdc++.h>
using namespace std;
int n,k;
char z;
string b[100005];
struct hu{
	int sz;
	char zm;
}a[105];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].sz>>a[i].zm;
	}
	for(int i=1;i<=n;i++){
		k=a[i].sz;
		z=a[i].zm;
		for(int j=1;j<=k;j++){
			cout<<z;
		}
	}
	return 0;
} 
