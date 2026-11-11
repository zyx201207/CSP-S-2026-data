#include<bits/stdc++.h>
using namespace std;
int b[200010],c[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	int maxs=-1,s=0,s1=1;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		maxs=max(maxs,c[i]);
	}
	while(s1<maxs){
		s++;
		s1*=2;
	}
	s1/=2;
	int so;
	for(int i=s;i>=0;i--){
		so=0;
		for(int j=1;j<=n;j++){
			if(c[j]>=s1){
				so++;
				c[j]-=s1;
				b[so]=c[j]+s1;
			}
		}
		if(so>=m){
			break;
		}
		memset(b,0,sizeof(0));
		s1/=2;
	}
	if(so>m) sort(b+1,b+so+1);
	int s2=b[so];
	for(int i=so-1;i>=so-m+1;i--) s2&=b[i];
	cout<<s2;
	return 0;
}
