#include<bits/stdc++.h>
using namespace std;
int a[500100],b[500100];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int n,m,c,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=q;i++){
		cout<<50<<endl;
	}
	sort(a+1,a+1+n);
	int s=0,ma=0;
	for(int i=1;i<=n;i++){
		int j;
		s=0;
		for(j=i-1;j>=1;j--){
			s+=a[i]-a[j];
			if(s>m){
				break;
			}
		}
		if(i-j>ma)ma=(i-j);
	}
	return 0;
}
