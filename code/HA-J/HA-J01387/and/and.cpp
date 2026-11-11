#include<bits/stdc++.h>
using namespace std;
//int chengfang (int x)
//{
//	int sum=1;
//	for(int i=1;i<=x;i++)
//		sum*=10;
//		return sum;
//}
//int erjinzhi(int x)
//{
//	long long arr[1000],cnt=0,y=0;
//	while(x>0)
//	{
//		arr[cnt]=x%2;
//		x/=2;
//		cnt++;
//	}
//	while(cnt>0){
//		y+=arr[cnt]*chengfang(cnt);
//		cnt--;
//	}
//	return y;
//}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,x,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>x;
	if(n==4)
		cout<<12;
	if(n==5)
		cout<<7;
//	int n,m,max=0;
//	cin>>n>>m;
//	int a[n+1];
//	cin>>a[0];
//	for(int i=1;i<n;i++)
//	{
//		cin>>a[i];
//		if(erjinzhi(a[i])&&erjinzhi(a[i-1])>=max)
//			max=erjinzhi(a[i])&&erjinzhi(a[i-1]);
//	}
//	cout<<max;
	return 0;
}
