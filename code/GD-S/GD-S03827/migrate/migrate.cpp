#include<iostream>
using namespace std;

struct aa{
	int x,y;
}small[2000010];

int c,T;
int n;
long long d;
long long a[2000010];
int t;
int can_l[2000010];
int can_r[2000010];
long long s;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;t=0;s=0;
		for(int i=1;i<=n;++i){
			can_l[i]=i;
			can_r[i]=i;
			cin>>a[i];
		}
		if(d==1){
			cout<<0<<endl;
			continue;
		}
		for(int i=4;i<=n;++i){
			int l1,l2,l3;
			l1=-1;
			int r=i;
			while(l1+1<r){
				int mi=(l1+r)/2;
				if(a[i]-a[mi]>d)l1=mi;
				else r=mi;
			}
			l1=r;
			l2=r+1;
			r=l2;
			l3=-1;
			while(l3+1<r){
				int mi=(l3+r)/2;
				if(a[l2+1]-a[mi]>d)l3=mi;
				else r=mi;
//				cout<<l3<<" "<<r<<" "<<mi<<endl;
			}
//			l3=r;
//			cout<<a[i]<<" "<<a[i-1]<<" "<<a[i-2]<<" "<<a[i-3]<<endl;
//			if(a[i]-a[i-3]>d&&a[i]-a[i-2]<=d&&a[i-1]-a[i-3]<=d){
//				small[++t]=i;
//			}
//			cout<<l3<<" "<<l1<<" "<<l2<<" "<<i<<endl;
//			if(a[i]-a[i-3]>d&&a[i]-a[i-2]<=d&&a[i-1]-a[i-3]<=d){
//				small[++t]={i-3,i};
//				continue;
//			}
			if(l3>=l1||l2>=i||l1==0||l3==0)continue;
			if(a[i]-a[l1]<=d&&a[l2]-a[l3]<=d&&a[i]-a[l3]>d){
				small[++t]={l3,i};
			}
		}
//		cout<<t;
		for(int i=1;i<=n;++i){
			int j=i;
			while(a[j+1]-a[j]<=d&&j+1<=n)++j;
			for(int k=i;k<=j;++k){
				can_l[k]=i;can_r[k]=j;
			}
			i=j;
		}
//		for(int i=1;i<=n;++i){
//			cout<<a[i]+1000000000000000000<<" ";
//			cout<<can_l[i]<<" "<<can_r[i]<<endl;
//		}
//		small[t+1]=n+1;
		small[t+1]={n+1,n+1};
		small[0]={0,0};
		for(int i=1;i<=t;++i){
			long long l=small[i].x-max(small[i-1].y-2,can_l[small[i].x])+1;
			long long r=min(small[i+1].x+2,can_r[small[i].y])-small[i].y+1;
//			cout<<l<<" "<<r<<endl;
//			cout<<small[i].x<<" "<<small[i].y<<endl; 
			s+=l*r;
		}
		cout<<s<<endl;
	}
	return 0;
} 
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
0 1
10 3
0 3 6 7 8 9 10 11 14 17
0 1
5 3
-3 0 2 3 4
0 1 
7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989
*/
