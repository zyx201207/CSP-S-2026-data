#include<bits/stdc++.h>//你疯了吗T2放这个。
#define int long long 
using namespace std;
int n,a[214514],l1,l2,r1,r2,m,s[214514],t[214514],ans;
char c[214514];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i] >> c[i];
		s[i]=s[i-1]+a[i];
		m+=a[i];
	}
	for(int i=n;i>=1;--i){
		t[i]=t[i+1]+a[i];
	}
	l1=1,r1=m;
	l2=1,r2=n;
	while(l1<=r1){
//		cout << l1 << ' ' << r1 << ' ' << l2 << ' ' << r2 << '\n';
		int A=s[l2]-l1+1,B=r1-s[r2-1];
		if(A>=B){
			ans+=(int)(c[l2]!=c[r2])*B;
			r1-=B;
			r2--;
			l1+=B;
			if(B==A){
				l2++;
			}
		}else{
			ans+=(int)(c[l2]!=c[r2])*A;
			l1+=A;
			l2++;
			r1-=A;	
		}
	}
	cout << ans;
	return 0;
} 
