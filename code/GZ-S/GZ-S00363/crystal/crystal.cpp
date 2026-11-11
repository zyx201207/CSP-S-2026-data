//刘骏瑞 贵阳市清华中学 GZ-S00363 
#include<bits/stdc++.h>
using namespace std;
long long sj[500005],cf[500005];
long long masum=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>sj[i];
	}
	sort(sj+1,sj+1+n);
	cf[n]=0;
	for(int i=n-1;i>0;i--){
		cf[i]=sj[n]-sj[i];
	}
	for(int i=n;i>=1;i--){
		long long nows=0;
		int nxb=i;
		long long cj=sj[n]-sj[i];
		long long cnt=0;
		while(nows<m){
			if((nows+cf[nxb]-cj)<=m&&nxb>0){
				cnt++;
				nows+=cf[nxb]-cj;
				nxb--;
			}
			else{
				break;
			}
		}
		masum=max(masum,cnt);
	}
	cout<<masum;
	return 0;
}
