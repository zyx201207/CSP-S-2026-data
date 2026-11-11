#include<bits/stdc++.h>
using namespace std;
using ci=const int;using ui=unsigned int;using cui=const unsigned int;using ll=long long;
using cll=const long long;using ull=unsigned long long;using cull=const unsigned long long;
template<class T>constexpr T& Min(T &x,const T y){
	return x<y?x:x=y;
}
template<class T>constexpr T& Max(T &x,const T y){
	return x<y?x=y:x;
}
cui oo=1u<<30;cull inf=1ull<<62;
cui N=2e6;
ui _,T,n;
ll d,a[N],b[N],c[N];
ull ans;
inline void run(){
	cin>>n>>d,ans=0;
	for(ui i=1;i<=n;i++)cin>>a[i];
	if(n<=10000){
		for(ui i=1;i<=n;i++){
			ui cnt=0;
			for(ui j=i,l=i,r=i-1;j<=n;j++){
				b[j]=0,c[j]=1;
				while(a[j]-a[l]>d)cnt-=c[l++];
				if(l==j&&i!=j)break;
				if(l>r){
					r=l,cnt=c[l];
					while(r+1<j&&b[r+1]==b[l])
						cnt+=c[++r];
				}
				b[j]=b[l]+1;
				c[j]=cnt;
				if(cnt==2)ans++;
//				cout<<i<<" "<<j<<":"<<cnt<<" "<<b[j]<<" "<<c[j]<<" "<<l<<" "<<r<<" "<<ans<<"\n";
			}
		}
	}else{
		for(ui i=1,j=1,k=1,l=1,r=1;i+3<=n;i++){
			if(j<i+2)j=i+2;
			while(j<n&&a[j+1]-a[i]<=d)++j;
			if(k<j+1)k=j+1;
			while(k<=n&&a[k]-a[j-2]<=d)++k;
			if(i<j-1&&k<=n&&a[j]-a[i]<=d&&a[k]-a[j-1]<=d&&a[k]-a[i]>d){
				if(r<=k){
					r=k;
					while(r<n&&a[r+1]-a[j-1]<=d)++r;
					ui rr=r-1;
					while(r<n&&a[r+1]-a[r]<=d&&a[r+1]-a[rr]>d)++r;
				}
				ui ll=(l=i)+1;
				while(l>1&&a[l]-a[l-1]<=d&&a[ll]-a[l-1]>d)--l;
				ans+=ull(i-l+1)*(r-k+1);
//				cout<<i<<" "<<j-1<<" "<<j<<" "<<k<<" "<<l<<" "<<r<<" "<<ans<<"\n";
			}
		}
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("migrate.in","r",stdin);freopen("migrate.out","w",stdout);
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>_>>T,a[0]=-inf;while(T--)run();
	return 0;
}
/*
0 1
197 66
0 2 66 68 69 132 135 136 198 202 203 264 269 270 330 336 337 396 403 404 462 470 471 528 537 538 594 604 605 660 671 672 726 738 739 792 805 806 858 872 873 924 939 940 990 1006 1007 1056 1073 1074 1122 1140 1141 1188 1207 1208 1254 1274 1275 1320 1341 1342 1386 1408 1409 1452 1475 1476 1518 1542 1543 1584 1609 1610 1650 1676 1677 1716 1743 1744 1782 1810 1811 1848 1877 1878 1914 1944 1945 1980 2011 2012 2046 2078 2079 2112 2145 2146 2178 2212 2213 2244 2279 2280 2310 2346 2347 2376 2413 2414 2442 2480 2481 2508 2547 2548 2574 2614 2615 2640 2681 2682 2706 2748 2749 2772 2815 2816 2838 2882 2883 2904 2949 2950 2970 3016 3017 3036 3083 3084 3102 3150 3151 3168 3217 3218 3234 3284 3285 3300 3351 3352 3366 3418 3419 3432 3485 3486 3498 3552 3553 3564 3619 3620 3630 3686 3687 3696 3753 3754 3762 3820 3821 3828 3887 3888 3894 3954 3955 3960 4021 4022 4026 4088 4089 4092 4155 4156 4158 4222 4223 4224 4289 4356 4421 4422 4487


0 1
6 3
0 1 2 3 4 7

0 1
7 6
0 4 8 10 12 14 18

0 1
6 12
-10 -6 -2 2 6 10

0 1
10 22
0 7 14 21 28 35 42 49 56 63

0 1
8 3
0 1 2 4 8 10 11 13

*/
