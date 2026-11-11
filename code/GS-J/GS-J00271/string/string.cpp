#include <iostream>
#include <string>
using namespace std;
const int N=2e5;
#define int long long
struct Node{
	char name;
	int num;
}a[N];
int n;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i].num>>a[i].name;
		sum+=a[i].num;
	}
	if(sum%2==1){
		int mid=(sum+1)/2;
//		cout<<sum<<' '<<mid<<' ';
		int l=1,r=n;
		int ans=0;
		int len1=0,len2=0;
		for(int i=1;i<mid;i++){
			len1++;
			len2++;
			if(len1>a[l].num){
				l++;
				len1-=a[l].num;
			}
			if(len2>a[r].num){
				r--;
				len2-=a[r].num;
			}
			if(a[l].name!=a[r].name){
				ans++;
			}
			
		}
		cout<<ans;
		return 0;
	}
	else{
		int mid=sum/2;
//		cout<<sum<<' '<<mid;
		int l=1,r=n;
		int ans=0;
		int len1=0,len2=0;
		for(int i=1;i<=mid;i++){
			if(len1>a[l].num){
				l++;
				len1-=a[l].num;
			}
			if(len2>a[r].num){
				r--;
				len2-=a[r].num;
			}
			if(a[l].name!=a[r].name){
				ans++;
			}
			len1++;
			len2++;
		}
		cout<<ans;
		return 0;
	}
}
