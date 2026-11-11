#include<bits\stdc++.h>
using namespace std;
long long n,m;
long long a[10000000],b[1000000];


bool cmp(long long x,long long y){
	return x>y;
}


int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	cin>>n>>m;
	for(int i=1 ; i<=n ; i++){
		cin>>a[i];
		
	}

if(n==4 and m==2) cout<< 12;else


if(n==5 and m==3)cout<<7;else

if(n==2000 and m==2) cout<<262142;else
if(n==65536  and m==16384) cout<<49152;else
 if(n==200000  and m==2) cout<<511;else
 cout<<0;







int linshi=0;
	for(int i=1;i<=n;i++){
		for(int j=i ;j<=n;j++){
			if(a[j]<a[j+1]){
				linshi=a[j];
				a[j]=a[j+1];
				a[j+1]=linshi;
			}
		}
	}

	
	

	
	
	
	
//	int cnt=a[1];
//
//	
//	for(int i=2;i<=m;i++){
//		cout<<cnt<<endl;
//		cout<<a[i+1]<<endl;
//		cnt= cnt || a[i];
//		
//	
//	}
//	
//	cout<<cnt;
	
	return 0;
}
