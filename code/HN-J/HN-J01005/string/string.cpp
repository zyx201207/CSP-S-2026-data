#include <bits/stdc++.h>
using namespace std;
struct p{
	int s;
	char a;
};
p x[200005];
int main(){
	freopen ("string.in","r",stdin);
	freopen ("string.out","w",stdout);
	long long int n,ans=0; cin>>n;
	for (int i=1;i<=n;i++){
		cin>>x[i].s>>x[i].a;
	}
	int i=1,j=n;
	while (j>i){
	if (i==j) break;
	if (x[i].a!=x[j].a){
		if (x[i].s>x[j].s){
			x[i].s-=x[j].s;
			ans+=x[j].s;
			j--;
		}
		else if (x[i].s<x[j].s){
			x[j].s-=x[i].s;
			ans+=x[i].s;
			i++;
		}
		else {
			ans+=x[j].s;
			j--;
			i++;
		}
	}
	else {
		if (x[i].s>x[j].s){
		x[i].s-=x[j].s;
		j--;
		}
		else if (x[i].s<x[j].s){
			x[j].s-=x[i].s;
			i++;
		}
		else {
			j--;
			i++;
		}
	}
	}
	cout<<ans;
}
