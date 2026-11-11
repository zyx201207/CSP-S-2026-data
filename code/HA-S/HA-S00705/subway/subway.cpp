#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,mi[500005],di[505],t[505],qi[500005],zo[500005];
bool find(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(di[i]==zo[j])
			return 1;
		}
	}
	return 0;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long k[500005];
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++){
		cin>>mi[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=2*n;j++){
			cin>>di[j];
			cout<<t[j];}}
	for(int i=1;i<=q;i++){
		cin>>qi[i];
		cout<<zo[i];}
	for(int i=1;i<=q;i++){
		if(find())
		cout<<mi[qi[i]]+t[zo[i]]+mi[zo[i]];
	}
	return 0;
} 
