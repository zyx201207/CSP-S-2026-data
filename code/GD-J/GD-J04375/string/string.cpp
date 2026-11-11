#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+10;
int n;
char a[N];
ll b[N],ans=0,sum1,sum2;
int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin >>n;
	for(int i=1;i<=n;i++){
		cin >>b[i]>>a[i];
	}
	int l=1,r=n;
	sum1=b[l],sum2=b[r];
	while(l<r){
		/*
		cout <<endl<<l<<" "<<r<<endl;
		cout <<a[l]<<" "<<a[r]<<endl;
		cout <<b[l]<<" "<<b[r]<<" "<<ans<<endl;
		*/
		if(b[l]==b[r]){
			if(a[l]!=a[r])ans+=b[r];
			l++;
			r--;
			sum1+=b[l];
			sum2+=b[r];	
		}else if(b[l]<b[r]){
			b[r]-=b[l];
			if(a[l]!=a[r])ans+=b[l];
			l++;
			sum1+=b[l];
		}else{
			b[l]-=b[r];
			if(a[l]!=a[r])ans+=b[r];
			r--;
			sum2+=b[r];
		}
	}
	cout <<ans;
//	cout <<endl<<sum1<<" "<<sum2;
	return 0;
}
/*
3
2 a
2 b
1 c
 6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
