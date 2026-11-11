#include<bits/stdc++.h>
using namespace std;
int a[200005];
char c[200005];
long long sl[200005],sr[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	long long n,len=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		len+=a[i];
	}
	for(int i=1;i<=n;i++){
		sl[i]=sl[i-1]+a[i];
//		cout<<sl[i]<<" ";
	}
//	cout<<'\n';
	for(int i=n;i>=1;i--){
		sr[i]=sr[i+1]+a[i];
//		cout<<sr[i]<<" ";
	}
//	cout<<'\n';+1;
//	int lastl=0,lastr=n+1;
//	long long ansl=0,ansr=n;
	long long sum=0,lastqey=0;
	for(int l=1,r=n;l<=r;){
		long long pl=sl[l],pr=sr[r];
//		long long lastpl=sl[l-1],lastpr=sl[r+1];
		if(pl>=pr){
			if(c[l]!=c[r])sum+=sr[r]-lastqey;
			r--;
//			cout<<"l"<<'\n';
		}else{
			if(c[l]!=c[r])sum+=sl[l]-lastqey; 
			l++;
//			cout<<"r"<<'\n';
		}
		lastqey=min(pl,pr);
	}
//	if(n%2==1)sum--;
	cout<<sum<<'\n';
	return 0;
}/*
6
3 a
2 c
1 b
1 c
2 b
2 a

3
2 a
2 b
1 c
fc string1.ans string1.out
fc string2.ans string2.out
fc string3.ans string3.out
fc string4.ans string4.out
fc string5.ans string5.out
fc string6.ans string6.out
*/
