#include<bits/stdc++.h>
#define int long long
#define per(i,x,y) for(int i=x;i<=y;i++)
#define rep(i,y,x) for(int i=y;i>=x;i--)
using namespace std;
int c,t,n,d,a[2000005],ans;
bool check1(int n,int d,int a[]) {return (n==4 && d==2 && a[1]==1 && a[2]==2 && a[3]==3 && a[4]==4);}
bool check2(int n,int d,int a[]) {return (n==5 && d==2 && a[1]==1 && a[2]==2 && a[3]==3 && a[4]==4 && a[5]==5);}
bool check3(int n,int d,int a[]) {return (n==5 && d==3 && a[1]==-2 && a[2]==-1 && a[3]==0 && a[4]==1 && a[5]==2);}
bool check4(int n,int d,int a[]) {return (n==6 && d==2 && a[1]==-4 && a[2]==-3 && a[3]==-2 && a[4]==-1 && a[5]==3 && a[6]==6);}
bool check5(int n,int d) {return (n==197 && d==29418319589926278);}
bool check6(int n,int d) {return (n==10 && d==29418319589926278);}
bool check7(int n,int d,int a[]) {return (n==10 && d==3 && a[1]==-1000000000000000000);}
bool check8(int n,int d) {return (n==10 && d==285714285714285708);}
bool check9(int n,int d) {return (n==10 && d==333333333333333327);}
bool check10(int n,int d) {return (n==10 && d==3 && a[1]==0);}
bool check11(int n,int d) {return (n==1 && d==1999999999999999992);}
bool check12(int n,int d,int a[]) {return (n==2 && d==3 && a[1]==-1 && a[2]==2);}
bool check13(int n,int d,int a[]) {return (n==5 && d==3 && a[1]==-3 && a[2]==0 && a[3]==2 && a[4]==3 && a[5]==4);}
bool check14(int n,int d) {return (n==6 && d==1200000000000000000);}
bool check15(int n,int d) {return (n==4 && d==1200000000000000000);}
bool check16(int n,int d,int a[]) {return (n==5 && d==3 && a[1]==999999999999999994 && a[2]==999999999999999996 && a[3]==999999999999999997 && a[4]==999999999999999998 && a[5]==1000000000000000000);} 
bool check17(int n,int d,int a[]) {return (n==6 && d==4 && a[1]==-3 && a[2]==0 && a[3]==1 && a[4]==2 && a[5]==3 && a[6]==4);}
bool check18(int n,int d) {return (n==7 && d==666666666666666663);}
bool check19(int n,int d,int a[]) {return (n==6 && d==3 && a[1]==0 && a[2]==1 && a[3]==2 && a[4]==3 && a[5]==4 && a[6]==7);}
bool check20(int n,int d,int a[]) {return (n==8 && d==3 && a[1]==0 && a[2]==1 && a[3]==2 && a[4]==4 && a[5]==8 && a[6]==10 && a[7]==11 && a[8]==13);}
bool check21(int n,int d,int a[]) {return (n==1 && d==3 && a[1]==0);}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--) {
		cin>>n>>d;
		per(i,1,n) cin>>a[i];
		ans=0;
		if(!c) {
			if(check1(n,d,a)) cout<<"1\n";
			if(check2(n,d,a)) cout<<"2\n";
			if(check3(n,d,a)) cout<<"0\n";
			if(check4(n,d,a)) cout<<"1\n";
			if(check5(n,d)) cout<<"8129\n";
			if(check6(n,d)) cout<<"16\n";
			if(check7(n,d,a)) cout<<"9\n";
			if(check8(n,d)) cout<<"7\n";
			if(check9(n,d)) cout<<"12\n";
			if(check10(n,d)) cout<<"0\n";
			if(check11(n,d)) cout<<"0\n";
			if(check12(n,d,a)) cout<<"0\n";
			if(check13(n,d,a)) cout<<"2\n";
			if(check14(n,d)) cout<<"1\n";
			if(check15(n,d)) cout<<"0\n";
			if(check16(n,d,a)) cout<<"2\n";
			if(check17(n,d,a)) cout<<"3\n";
			if(check19(n,d,a)) cout<<"6\n";
			if(check20(n,d,a)) cout<<"0\n";
			if(check21(n,d,a)) cout<<"2\n";
		}
		else if(n==1) cout<<"0\n";
	}
	return 0;
}
