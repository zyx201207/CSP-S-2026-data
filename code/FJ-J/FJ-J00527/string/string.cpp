#include<bits/stdc++.h>
using namespace std;
const int MAXX=2e5+5;
int n,a[MAXX];
char c[MAXX];
long long sum=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	long long l=1,r=n,lt=a[l],rt=a[r];
	while(l<r){
		if(c[l]!=c[r]){
			if(lt>rt){
				sum+=rt;
				lt-=rt;
				r--;
				rt=a[r];
			}else if(lt<rt){
				sum+=lt;
				rt-=lt;
				l++;
				lt=a[l];
			}else{
				sum+=lt;
				l++;
				r--;
				lt=a[l],rt=a[r];
			}
		}else if(c[l]==c[r]){
			if(lt>rt){
				lt-=rt;
				r--;
				rt=a[r];
			}else if(lt<rt){
				rt-=lt;
				l++;
				lt=a[l];
			}else{
				l++;
				r--;
				lt=a[l],rt=a[r];
			}
		}
	}
	cout<<sum;
	return 0;
}
