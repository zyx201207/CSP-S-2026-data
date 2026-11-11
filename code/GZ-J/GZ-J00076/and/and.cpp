//GZ-J00076 贵阳市第三中学 吴钰辉 
#include<bits/stdc++.h>
using namespace std;
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	vector<long long>a(n);
	for(long long i=0;i<n;i++)cin>>a[i];
	sort(a.begin(),a.end(),cmp);
	long long sum=a[0]&a[1];
	for(long long i=2;i<m;i++){
		sum&=a[i];
	}
	cout<<sum;
    return 0;
}
