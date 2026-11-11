#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=5e5+50;
ll n,m;
ll a[N],qz[N];
ll qsum(int r,int lon){
	if(r>=lon) return qz[r]-qz[r-lon];
	else return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) qz[i]=qz[i-1]+a[i];
	ll st,mxlen=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]*(i-1)-qz[i-1] > m){
			st=i,mxlen=i-1;
			break;
		}
	}
	for(int i=st;i<=n;i++){
		ll qls;//前len个的和 
		while(1){
			
			qls=qsum(i-1,(mxlen+1)-1);
	//		cout<<i<<" "<<mxlen<<" "<<qls<<endl;
			if(a[i]*((mxlen+1)-1)-qls<m){
				mxlen++;
			}
			else break;
		} 
	}
	cout<<mxlen<<endl;
	return 0;
}
