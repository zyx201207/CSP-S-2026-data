#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N=2e5+10;
ll a[N][5],n,sum=0,ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		char asdf;
		cin>>a[i][1]>>asdf;
		a[i][2]=asdf;
		sum+=a[i][1];
	}
	int x=1,y=n;
	while(x<y){
		//cout<<a[x][1]<<char(a[x][2])<<" "<<a[y][1]<<char(a[y][2])<<" "<<x<<" "<<y<<" ";
		if(a[x][1]>a[y][1]){
			if(a[x][2]!=a[y][2]){
				ans+=a[y][1];
				a[y][2]=a[x][2];
			}
			a[x][1]-=a[y][1];
			y--;
		}else if(a[x][1]<a[y][1]){
			if(a[x][2]!=a[y][2]){
				ans+=a[x][1];
				a[x][2]=a[y][2];
			}
			a[y][1]-=a[x][1];
			x++;
		}else{
			if(a[x][2]!=a[y][2]) ans+=a[x][1];
			x++,y--;
		}
		//cout<<ans<<endl;
	}
	cout<<ans;
	return 0;
}

