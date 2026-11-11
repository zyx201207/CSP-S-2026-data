#include<bits/stdc++.h>
using namespace std;
int t,y,n,m,s;
int c[500050];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>c[i];
	for(int i=0;i<n-1;i++){
		for(int j=1;j<n;j++){
			if(c[j-1]>c[j]){
				swap(c[j-1],c[j]);
			}
		}
	}
	y=n;
	int e=n;
	while(e>=1){
		int neng=m;
		t=c[y];
		for(int i=y-1;i>=0;i--){
			neng-=abs(t-c[i]);
			if(neng<0){
				s=max(s,y-e);
				break;
			}
			e=i;
		}
		y--;
	}
	s++;
	cout<<s;
	return 0;
}
