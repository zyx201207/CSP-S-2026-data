#include<bits/stdc++.h>
using namespace std;
int a[200005];
int an(int s,int d){
	int i=0,a=0,y=0;
	int m=2;
	while(s!=0||d!=0){
		if(s%2&&d%2){
			a+=2^i;
			y++;
		}
		m=2;
		s/=2;
		d/=2;
		i++;
	}
	return a;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	int max=-1;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;++j){
			if(max<an(a[i],a[j])) max=an(a[i],a[j]);
		}
	}
	cout<<max;
    return 0;
}
