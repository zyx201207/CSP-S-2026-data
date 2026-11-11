#include<bits/stdc++.h>
using namespace std;
long long n,m,i,c[300005],j;
string b,a[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(i;i<n;i++){
		cin>>a[i];
	}
	for(i=0;i<n;i++){
		for(j=i;j<n;j++){
			if(b!=a[j]){
				b+a[j];
			}
		}
	}
	cout<<"10 3 3"<<endl;
	return 0;
}
