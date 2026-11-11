#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m;
int a[N],a_1[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			a_1[i]=a[j];
			for(int k=1;k<=n;k++){
				if(a_1[k]==m){
					cout<<i<<" ";
					break;
				}
			}
		}
	}
	return 0;
}

