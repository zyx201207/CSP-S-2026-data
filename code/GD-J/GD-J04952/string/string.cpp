#include <bits/stdc++.h>
using namespace std;

const int N=2*1000*100+10;

int a[N];
char c[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n;
	cin >>n;
	
	for (int i=1;i<=n;i++){
		cin >>a[i]>>c[i];
		
	}
	
	int j=n;
	int cnt=0;
	long long ans=0;//¼ÆÊý£¬´ð°¸ 
	bool f=false;
	for (int i=1;i<=n;i++){
		
		while (a[i]>0){
			if (i==j||abs(i-j)==1){
//				cout <<"yes";
				
				if (abs(i-j)==1&&c[i]!=c[j])ans+=min(a[i],a[j]);
			
				f=true;
				break;
			}
			
			
			if (c[i]!=c[j])ans+=min(a[i],a[j]);
			if (a[i]<a[j]){
				a[i]=0;
				a[j]-=a[i];
			}
			else {
				a[i]-=a[j];
				j--;
			}
			
		}
		
//		cout <<ans<<'\n';
		
		if (f)break;
	}
	
	
	cout <<ans;
	
	return 0;
}
