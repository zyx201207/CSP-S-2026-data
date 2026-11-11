#include<bits/stdc++.h>
using namespace std;
int n;
struct st {
	int sz;
	string zm;
}a[100005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string,out","w",stdout);
	cin>>n;
	int cnt=0 ,ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i].sz>>a[i].zm;
	}
	int i=1,j=n;
	bool k=1;
	while (i<=j){
		if(a[i].zm!=a[j].zm){
			k=0;
		}
		i++,j--;
	}
	if(k==1) cout<<0;
    return 0;
}
