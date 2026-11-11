#include<bits/stdc++.h>
using namespace std;
struct num{
	long long amt;
	char c;
};
num a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int k=1;
	for(int i=1;i<=n;i++){
		num m;
		cin>>m.amt>>m.c;
		if(a[k-1].c==m.c)a[k-1].amt+=m.amt;
		else{
			a[k].amt=m.amt;
			a[k].c=m.c;
			k++;
		}
	}
	long long ans=0;
	int i=1,j=k-1;
	while(i<j){
		if(a[i].c!=a[j].c)ans++;
		a[i].amt--;a[j].amt--;
		if(a[i].amt<=0)i++;
		if(a[j].amt<=0)j--;
	}
	cout<<ans;
	return 0;
}

