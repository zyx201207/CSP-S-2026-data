#include<bits/stdc++.h>
using namespace std;
#define FILE "migrate"
int c,t,n;
long long x[2000001],d;
int paths[200001],dis[200001];
int nxt[2000001][22];
int main(){
	freopen(FILE".in","r",stdin);
	freopen(FILE".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		for(int i=1;i<=n;i++){
			cin >> x[i];
		}
		x[n+1]=x[n+2]=0x3f3f3f3f3f3f3f3fll;
//		cerr << "n=" << n << ", d=" <<d << ", delta=" << x[2]-x[1] << ".\n";
//		continue; 
		if(n>=100000){
			if(c==13 || c==14){
			int ans=0;
			for(int i=1;i+3<=n;i++){
				if(x[i+3]-x[i]>d && x[i+2]-x[i]<=d && x[i+3]-x[i+1]<=d)	++ans;
			}
			cout << ans << '\n';
			continue;
		}
		if(c==11 || c==12){
			if(d<=x[2]-x[1]){
				cout << 0 << '\n';
				continue;
			}
			cout << max(n-2*(d/(x[2]-x[1]))+1,0ll) << '\n';
			continue;
		}
		}
		long long ans=0;
		for(int i=1;i<=n;i++){
			paths[i]=1,paths[i-1]=0;
			dis[i]=0;
			for(int j=i+1,p=i,p2=i;j<=n;j++){
				paths[j]=paths[j-1];
				while(x[p]<x[j]-d)	p++;
				if(j==p)	break;
				dis[j]=dis[p]+1;
				
				while(p2+1<=j && dis[p2+1]<=dis[p])	p2++;
//				cerr << "dis(i=" << i << ", j=" << j << ")=" << dis[j] << "; p=" << p << ", p2=" << p2 << ".\n";
				int tmp=min(paths[p2]-paths[p-1],3);
//				cerr << "tmp=" << tmp << ".\n";
				paths[j]+=tmp;
				if(tmp==2){
					ans++;
//					cerr << "(i=" << i << ", j=" << j << ", p=" << p << ").\n";
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
/*
统计满足x[j+1]-d<=x[l]<x[j+2]-d, x[j-1]+d<x[r]<=x[j]+d的(l,r)对
l: 只有[xi,xi+d]内恰好有一个数的i会参与候选
r: 只有[xi-d,xi]内恰好有一个数的i会参与候选 

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 1
10 3
0 3 6 7 8 9 10 13 16 19

0 1
10 3
0 3 6 7 8 9 10 11 14 17

0 1
10 333333333333333327
-1000000000000000000 -666666666666666673 -333333333333333346 -111111111111111128 111111111111111090 222222222222222199 333333333333333308 444444444444444417 666666666666666635 999999999999999962

0 1
10 3
0 3 6 9 11 12 14 14 17 20
2 3 4 6  8  8  9  9 10 10

13 2
10 114
1 2 3 4 5 6 7 8 9 10
10 4
1 1 1 1 5 9 9 9 9 9
*/
