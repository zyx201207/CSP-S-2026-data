#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],an,maan,y;
bool f;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		//scanf("&lld",&a[i]);
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	maan=0;
	f=0;
	for(int i=1;i<=n;i++){
		an=1;
		y=m;
		for(int j=i-1;j>=1;j--){
			y=y-(a[i]-a[j]);
			//cout<<y<<endl;
			if(y>=0){
				an++;
			}
			else{
				break;
			}
		}
		//cout<<an;
		maan=max(maan,an);
	}
	cout<<maan;
	return 0;
} 
