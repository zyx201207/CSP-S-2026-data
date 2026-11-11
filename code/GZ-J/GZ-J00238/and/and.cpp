//GZ-J00238 中央民族大学附属中学贵阳学校  杨忠瀚 
#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	long long ll=a[n],cnt=0;
	for(int i=n;i>=n-2;i--)ll=a[i]&ll;
	cout<<ll;
	return 0;
}
