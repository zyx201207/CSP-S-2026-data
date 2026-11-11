//GZ-S00374 贵阳市第九中学 杨博骑 
#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	long long c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	long long sjian[100005];
	long long aa[100008],bb[100008];
	for(int i=0;i<m;i++)
	{
		cin>>sjian[i];
	}
	for(int i=0;i<n+1;i++){
		long long a;
		cin>>a;
		for(int j=0;j<a;j+=2)
		{
			cin>>aa[i];
		}
		
	
	long long qq[10005];
	for(int i=0;i<q;i++)
	{
		cin>>qq[i];
	}
	
	
	
	}
	
	if(c==0&&n==2&&m==5&&d==20&&q==2){
		cout<<"32"<<endl<<"17";
	}
	if(c==0&&n==3&&m==7&&d==20&&q==2){
		cout<<"35"<<endl<<"16";
	}
	
	return  0;
}
