#include<bits/stdc++.h>
using namespace std;
const int N=1e5*5+10;
long long n,m,arr[N],maxn=-100,s1,b;
void brr(long long a)
{
	for(int i=0;i<n;i++)
	{
		if(arr[i]<a){
			while(arr[i]<a){
				arr[i]+=1;
				b-=1;
				if(b<=0)break;
			}
			if(b<=0)break;
		}
		if(b<=0)break;
	}
	int s=0;
	for(int i=0;i<n;i++){
		if(arr[i]==a)s+=1;	
	}
	if(maxn<s)maxn=s;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>arr[i];
	for(int i=0;i<n;i++)
	{
		b=m;
		brr(arr[i]);
	}
	cout<<maxn;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
