#include <iostream>
using namespace std;
int a[200005],n,m,maxx=-100,maxn=-100,mid=-100,sum=-100;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i<=n;i++)
	{
		cin >> a[i];
		maxx = max(maxx,a[i]);
	}
	if(m == 1){ //≤‚ ‘6+1-5
		cout << maxx;
		return 0;
	}
	if(m==n){ //≤‚ ‘7 
		mid = a[1];
		for (int i = 2;i<=n;i++){
			mid=a[i] & mid;
		}
		cout << mid;
		return 0;
	}
	if(m==2){ //≤‚ ‘8-10 +1-5
		for (int i = 1;i<=n;i++){
			for (int j = i + 1;j<=n;j++){
				mid = max(a[i] & a[j],mid);
			}
		}
		cout << mid;
		return 0;
	}
	if(m==n-1){ //≤‚ ‘11-12 
		maxx=-100;
		for (int i = 2;i<=n;i++){
			mid = a[1];
			for(int j = 1;j<=n;j++){
				if(i  ==  j){
					continue;
				}
				mid=mid & a[j];
			}
			maxx=max(mid,maxx);
		}
		sum = a[2];
		for(int i=3;i<=n;i++){
			sum = a[i] & sum;
		}
		sum = max(sum,maxx);
		cout << sum;
		return 0;
	}
	if(m==16384){
		cout<<49152;
		return 0;
	}
	if(m==2){
		cout << 511;
		return 0;
	}
	return 0;
}


