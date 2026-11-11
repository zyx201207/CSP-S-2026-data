#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<map>
#define LL long long
const int N=1e5+10;
const int Inf=0x3f3f3f3f;
using namespace std;
LL a[N],n,sum;
LL vc[N],j,ans,k;
string s;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		vc[i]=vc[i-1]+a[i];
	}j=n;
	for(LL i=1;i<=j;i++){
		sum=k;
		if(a[i]!=a[j+1])ans+=k;
//		if(vc[i]>vc[n]/2){
//			while(vc[n]/2>=sum){
//				sum+=a[j];
//				if(c[i]!=c[j])
//					if(sum>vc[n]/2){
//						ans+=sum-a[i];
//						k=a[j]-sum+a[i];
//					}else ans+=a[j];
//				j--;
//			}
//			break;
//		}
		while(a[i]>=sum){
			sum+=a[j];
			if(c[i]!=c[j])
				if(sum>a[i]){
					ans+=sum-a[i];
					k=a[j]-sum+a[i];
				}else ans+=a[j];
			j--;
		}
	}
	cout<<ans;
	return 0;
}

