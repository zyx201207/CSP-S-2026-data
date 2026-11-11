#include<bits/stdc++.h>
using namespace std;
const int ll=1e5+5;
long long n,m,ans=1;
long long a[ll];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(long long i=1;i<n;i++){
		long long k=m,w=a[i],sum=1;
		for(int j=i+1;j<=n;j++){
			if((a[j]-w)*sum<=k){
				k=k-(a[j]-w)*sum;
				sum++;
				w=a[j];
			}
			else{
				break;
			}
		}
		ans=max(ans,sum);
	}
	cout<<ans;
	return 0;
} 
/*
100 100000000
1 2 3 4 5 6 7 8 9 10
11 12 13 14 15 16 17 18 19 20
21 22 23 24 25 26 27 28 29 30
31 32 33 34 35 36 37 38 39 40
41 42 43 44 45 46 47 48 49 50
51 52 53 54 55 56 57 58 59 60
61 62 63 64 65 66 67 68 69 70
71 72 73 74 75 76 77 78 79 80
81 82 83 84 85 86 87 88 89 90
91 92 93 94 95 96 97 98 99 100
*/

