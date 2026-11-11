#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long shj[n+10],qzh[n+10],zhong[n+10];
	qzh[0]=0;
	long long j;
	for(long long i=1;i<=n;i++){
		cin>>shj[i];
	}
	sort(shj,shj+n+1);
	for(long long i=1;i<=n;i++){
	    qzh[i]=qzh[i-1]+shj[i];
	}
	int i=1;
	for(j=1;j<=n;j++){
		zhong[j]=qzh[j]+m;
		int j2=zhong[j]/3;
		if((qzh[j]+m+shj[j+1])/3<j2){
			if((qzh[j]+m+shj[j+1]-qzh[i])/3<j2){
				break;
			}
			i++;
		}
	}
	cout<<j-1;
	return 0;
}
