//  GZ-J00064  兰椿楸  毕节七星关东辰实验学校
#include<iostream>
#include<cmath>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,ans=0;
	long long a[1000000];
	cin>>n,m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	ans=a[2];
	cout<<ans;

	fclose(stdin);
	fclose(stdout);
	return 0;
}
