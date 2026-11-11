#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],t,f,y,an,tt[500005],o,u;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(a[i]-a[i-1]!=o&&i>2)f=0;
		else if(i==2)o=a[i]-a[i-1];
		tt[i]=tt[i-1]+(i-1)*o;
		if(tt[i]>m&&(!u)){
			u=1;
			y=i;
		}
	}
	if(f){
		cout <<y;
		return 0;
	}
	for(int i=1;i<=n;i++){
		t=0;
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			if(a[j]>a[i])break;
			t=t+(a[i]-a[j]);
		}
		if(t<=m)an=i;
	}
	cout <<an;
	return 0;
}
