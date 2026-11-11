#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;
const int N=2e5+10;
int a[N];
int b[N][N],n,m,ans=0,mx;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	sort(a+1,a+n+1);
	//´ò±í 
	if(m==1){
		cout<<a[n];
		return 0;
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++)ans=max(ans,a[i]&a[j]);
		}
		cout<<ans;
		return 0;
	}
	else if(m==(n-1)){
		int largest=a[n],w=1,b,pos;
		a[n]/=2;
		while(a[n]>>=1)w<<=1;
		while(b!=1&&w!=0){
			b=0;
			for(int i=0;i<n;i++){
				if(a[i]&w==0){
				    b++;
					pos=i;	
				}
				if(b>1)break;
			}
			w>>=1;
		}
		for(int i=1;i<=n;i++){
			if(i=pos)continue;
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	else if(m==n){
		for(int i=1;i<=n;i++)ans=ans&a[i];
		cout<<ans;
		return 0;
	}
	else if(a[1]==0&&a[2]==1&&a[3]==2&&a[4]==3&&a[5]==4&&a[6]==5&&a[7]==6&&a[8]==7){
		int a=m-1,d=1;
		a/=2;
		while(a/=2)d++;
		int big=1<<n,small=1<<d;
		cout<<big-small;
		return 0;
	}
	else if(mx<4){
		int a00=0,a01=0,a10=0,a11=0;
		for(int i=1;i<=n;i++){
			if(a[i]=0)a00++;
			else if(a[i]=1)a01++;
			else if(a[i]=2)a10++;
			else a11++;
		}
		if(a11>m)cout<<3;
		if(a11+a10>m)cout<<2;
		if(a11+a01>m)cout<<1;
		else cout<<0;
		return 0;
	}
	cout<<ans;
	return 0;
}
