#include <iostream>
#include <cmath>
using namespace std;
int a[114514];
long long p(long long n,long long dep,const long long m,long long num){
	if(dep == m) return a[num];
	long long maxx = -1;
	for(int i = dep-1;i < n - (m - dep);i++){
		long long usin = (a[i] & p(n,dep+1,m,i + 1));
		if(usin > maxx){
			maxx = usin;
		}
	}return maxx;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin >> n >> m;
	for(int i = 0;i < n;i++){
		cin >> a[i];
	}cout << p(n,1,m,1);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
