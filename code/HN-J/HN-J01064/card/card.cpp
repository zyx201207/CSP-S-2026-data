#include<bits/stdc++.h>
using namespace std;
long long t[100005],c[100005],n,m,z[100005],a;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>c[i];
	}
	for(int i=0;i<n;i++){
		t[i-a]=c[i];
		for(int l=0;l<i;l++){
			if(t[i]==t[l]){
				t[0]=c[i];
				a+=l;
				break;
			} 
			for(int l=0;l<i-a;l++) z[t[l]]++;
		}
	}
	for(int i=0;i<m;i++) cout<<z[i]<<' ';
	return 0;
}
