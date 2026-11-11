#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,ma=0,cnt;
	cin>>n>>m;
	int op[n]={},qz[n]={};
	for(int i=0;i<n;i++)cin>>op[i];
	sort(op,op+n);
	qz[0]=op[0];
	for(int i=1;i<n;i++)qz[i]=qz[i-1]+i*op[i]-i*op[i-1];
	/*c
	for(int i=0;i<n;i++){
		cout<<qz[i]<<" ";
	}
	cout<<endl;*/
	for(int i=0;i<n;i++){
		cnt=1;
		for(int j=i+1;j<n;j++){
			if(qz[j]-qz[i]>m){
				break;
			}
			cnt++;
			//cout<<j<<" ";
			//cout<<i<<" "<<j<<" "<<cnt<<"\n";
		}
		ma=max(ma,cnt);
		//cout<<"\n";
	}
	cout<<ma;
	//cout<<-1;
	return 0;
}
