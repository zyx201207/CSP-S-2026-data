//#include<bits/stdc++.h>
//using namespace std;
//
//int c,t,n,ans,anss;
//unsigned long long d;
//long long x[2000005];
//int f[2000005];
//
//void dfs(int start,int end)
//{
//	f[1]=0;
//	for(unsigned long long i=start; i<=end; i++) {
//		int tmp=0;
//		for(int j=0; j<d+1&&i-j>=start; j++) {
//			if(x[i]-x[i-j]<=d)
//				f[i]=min(f[i],f[i-j]+1);
//		}
//
//	}
//
//
//}
//
//int count(int start,int end)
//{
//	for(int i=0; i<=n; i++)f[i]=1000000000;
//	dfs(start,end);
//	ans=0;
//
//	for(int i=end-1; i>start; i--)
//		if(f[i]==f[end]-1) {
//			cout<<f[i]<<" "<<f[end]<<" "<<i<<endl;
//			ans++;
//		}
//	return ans;
//}
//
//
//int main()
//{
//
//	freopen("migrate.in","r",stdin);
//	freopen("migrate.out","w",stdout);
//	for(int i=0; i<=2000004; i++)f[i]=1000000000;
//	cin>>c>>t;
//	for(int z=0; z<t; z++) {
//		anss=0;
//
//		cin>>n>>d;
//		for(int i=1; i<=n; i++)cin>>x[i];
//
//		for(int i=1; i<=n; i++) {
//			for(int j=i+1; j<=n; j++) {
//				if(count(i,j)==2)anss++;
//			}
//		}
//
//		cout<<anss<<endl<<endl;
////		cout<<f[n]<<endl<<f[n-1]<<endl;
//	}
//
//
//	return 0;
//}
//



#include<bits/stdc++.h>
using namespace std;

int c,t,n,ans,anss;
unsigned long long d;
long long x[2000005];
int f[2000005];

void dfs(int start,int end)
{
	f[1]=0;
	for(unsigned long long i=start; i<=end; i++) {
		int tmp=0;
		for(int j=0; i-j>=start&&j<i; j++) {
			if(x[i]-x[i-j]<=d)
				f[i]=min(f[i],f[i-j]+1);
		}

	}


}

int count(int start,int end)
{
	for(int i=0; i<=n; i++)f[i]=1000000000;
	dfs(start,end);
	ans=0;

	for(int i=end-1; i>start; i--)
		if(f[i]==f[end]-1) {
//			cout<<f[i]<<" "<<f[end]<<" "<<i<<endl;
			ans++;
		}
	return ans;
}


int main()
{

	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	for(int i=0; i<=2000004; i++)f[i]=1000000000;
	cin>>c>>t;
	for(int z=0; z<t; z++) {
		anss=0;

		cin>>n>>d;
		for(int i=1; i<=n; i++)cin>>x[i];

		for(int i=1; i<=n; i++) {
			for(int j=i+1; j<=n; j++) {
				if(count(i,j)==2)anss++;
			}
		}

		cout<<anss<<endl;
//		cout<<f[n]<<endl<<f[n-1]<<endl;
	}


	return 0;
}



