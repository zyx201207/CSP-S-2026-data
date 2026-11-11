#include<bits/stdc++.h>
using namespace std;
const int N=5e5+100;
int a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	//cin>>n>>m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	int L=1,R=n;
//	int NUM=1;
	while(L<R){
		
		int average=(L+R)>>1;
		int mid=a[average];
		bool f=true;
		int sum=0;
//		cout<<NUM<<". average:"<<average<<" mid:"<<mid<<" m:"<<m<<" sum:"<<sum<<" F:"<<f<<endl;
		for(int i=1;i<=average;i++){
			if(sum-a[i]+mid<=m){
				sum+=mid-a[i];
			}
			else {
				f=false;
				break;
			}
		}
		
//		cout<<NUM<<". average:"<<average<<" mid:"<<mid<<" m:"<<m<<" sum:"<<sum<<" F:"<<f<<endl;
//		for(int i=1;i<=n;i++){
//			printf("%d ",a[i]);
//		}
//		printf("\n");
		
		if(f==true){
			for(int i=1;i<=average;i++) a[i]=mid;
			m-=sum;
			L=average+1;
		}
		else {
			R=average-1;
		}
//		NUM++; 
	}
//	printf("\n");
	int cnt=1;
	for(int i=1;i<=n;i++){
		if(a[i+1]==a[i]) cnt++;
//		printf("%d ",a[i]);
	}
	printf("%d\n",cnt);

 return 0;
}

