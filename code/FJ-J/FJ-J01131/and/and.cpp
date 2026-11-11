#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
int n,m;
ll a[200010],l=1,maxx=0,sum=0,maxsum=0;
bool s[200010][31],v[200010]={},tp1=1,vv[200010]={},awaaw=0;
void ejzzh(ll x,int iii){
	int to=0,aw=0;
	bool aww[31]={};
	while (x>0){
		aww[++to]=x%2;
		aw+=x%2;
		x/=2;
	}
	s[iii][0]=aw;
	for (int i=1;i<=to;i++){
		s[iii][l+1-i]=aww[i];
		//cout<<1-i+to<<" ";
	}
	//cout<<endl;
	return;
}
void awa(){
	for (int i=1;i<=n;i++) v[i]=vv[i];
}
/*
10 5
1 2 3 4 5 6 7 8 9 10
*/
int main(){
	freopen("and5.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	memset(s,0,sizeof(s));
	memset(v,1,sizeof(v));
	memset(vv,1,sizeof(vv));
	for (int i=1;i<=n;i++){
		cin>>a[i];
		tp1=tp1&log2(a[i]+1)==(int)log2(a[i]+1);
		maxx=max(maxx,a[i]);	
	}
	if (tp1){
		sort(a+1,a+1+n);
		cout<<a[n-m+1];
		return 0;
	}
	for (int i=1;;i++){
		if (l>maxx){
			l=i-1;
			break;
		}
		l*=2;
	}
	for (int i=1;i<=n;i++) ejzzh(a[i],i);
	bool startt=0;
	for (int j=1;j<=l;j++){
		int ff=0;
		for (int i=1;i<=n;i++){
			if (startt&&!vv[i]) continue;
			if (!s[i][j]&&startt) vv[i]=0;
			ff+=s[i][j];
			//cout<<"a["<<i<<"]="<<a[i]<<" ";
		}
		//cout<<endl<<j<<" "<<ff<<endl;
		ll ssum=1ll*pow(2,31)-1;
		int iiiii=1;
		for (int i=1;i<=n&&iiiii<=m;i++){
			if (v[i]==1){
				//cout<<i<<" ";
				iiiii++;
				ssum=(ssum&a[i]);
			}
		}
		if (iiiii==m+1) awaaw=1;
		if (iiiii==m+1) maxsum=max(maxsum,1ll*ssum);
		//cout<<ssum<<" ";
		if (ff>m) if (startt==0) j--,startt=1;
		awa();
	}
	int ff=1;
	sum=1ll*pow(2,31)-1;
	for (int i=1;i<=n&&ff<=m;i++){
		if (v[i]==1){
			//cout<<a[i]<<" ";
			sum=(sum&a[i]);
			ff++;
		}
	}
	if (ff==m+1) maxsum=max(maxsum,sum);
	if (ff!=m&&!awaaw) cout<<0;
	else cout<<maxsum;
	return 0;
}
/*
4 2
3 15 12 12
01111
01100
01100
00010
*sorted
huh
i think i can make an sqare like this and found:
the leftest,and the kuan=m,sqare
and bianli
|
01111
01100
01100
00010  chose:
||
01111
01100
01100
00010  chose:1 2
yea
11 1111 1111 1111 1110  11 1111 1111 1111 1111
*/
