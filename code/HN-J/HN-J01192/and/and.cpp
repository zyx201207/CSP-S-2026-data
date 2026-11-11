#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pr pair<int,int>
#define fi first
#define se second
int a[200005];
int nxt[200005][31];
int sum[200005][31];
signed main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	std::ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, m, s=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1, a+n+1);
	for(int j=30;j>=0;j--){
		nxt[n+1][j]=n+1;
		for(int i=n;i>=1;i--)
			if(a[i]&(1<<j))
				nxt[i][j]=i, sum[i][j]=sum[i+1][j]+1;
			else
				nxt[i][j]=nxt[i+1][j], sum[i][j]=sum[i+1][j];
	} 
	for(int i=30, l=1;i>=0;i--)
		if(sum[l][i]>=m)
			s+=(1<<i), l=nxt[l][i];
	cout<<s;
	return 0;
}
/*
Y           Y            A                                  CCCCCC                   A               TTTTTTTTTTTT
 Y         Y            A A                                C      C                 A A                    T
  Y       Y            A   A                              C        C               A   A                   T
   Y     Y            A     A                            C          C             A     A                  T
    Y   Y            A       A                           C                       A       A                 T
     Y Y            A         A                         C                       A         A                T
      Y            AAAAAAAAAAAAA                        C                      AAAAAAAAAAAAA               T
      Y           A             A                       C                     A             A              T
      Y          A               A                       C                   A               A             T
      Y         A                 A                      C          C       A                 A            T
      Y        A                   A                      C        C       A                   A           T
      Y       A                     A                      C      C       A                     A          T
      Y      A                       A                      CCCCCC       A                       A         T
      */
