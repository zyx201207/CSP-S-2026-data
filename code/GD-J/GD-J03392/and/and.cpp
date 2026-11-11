#include <bits/stdc++.h>

using namespace std;

int n,m;
vector <long long> a; 
long long cin_temp;
long long maxx=0;

int main(){
	freopen("and.in","r",stdin);//Ò»¶¨È¥×¢ÊÍ£¡ 
	freopen("and.out","w",stdout);
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>cin_temp;
		a.push_back(cin_temp);
	}
	sort(a.begin(),a.end());
	for(int i=0;i<=n-m;i++){
		long long counter=a[i];
		for(int j=i+1;j<i+m;j++)
			counter=(counter & a[j]);
		maxx=max(maxx,counter);
	}
	cout<<maxx;
	return 0;
}
/*

64  0010 0000
32  0001 0000
31  0001 1111
3   0000 0011
1   0000 0001
15  0000 1111
7   0000 0111

5 3
31 3 1 15 7

*/
