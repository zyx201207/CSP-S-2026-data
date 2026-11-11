#include<bits/stdc++.h> 
using namespace std;
//priority_queue<long long,vector<long long>,greater<long long>>a;
//long long cmp(long long x,long long y){
//	return x>y;
//}
long long s[600050];long long v[600050];
long long n,m,ans=1,sum=0,akm=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>s[i];
	}
	sort(s,s+n);
	for(int i=1;i<n;i++){
		v[i]=s[i]-s[i-1];
	}
	v[0]=99999999;
	v[n]=-9;
	for(int i=n;i>0;i--){
		sum=0,akm=0;
		if(ans>=i){
			cout<<ans;
			return 0;
		}
		for(int j=i;j>=0;j--){//if(v[j-2]!=0)
			akm+=v[j-1];
			sum+=akm;//cout<<j<<" "<<sum<<endl;
			if(sum>m){
				if(ans<i-j+1){
					ans=i-j+1;
				}
				break;
			}/*if(sum==m&&j==1){cout<<i<<" "<<j<<" ";
				if(ans<i-j+1){
					ans=i-j+1;
				}break;*/
			}

		//cout<<endl;	
		}
	cout<<ans; 
	return 0;
}

