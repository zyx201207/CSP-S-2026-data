#include<bits/stdc++.h>
using namespace std;
map<long long,int>mp;
long long a[500010],b[5010][5010],cnt,s;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,ma=INT_MIN,A=1,B=1;
	cin>>n>>m;
	if(m==0){
		for(int i=1;i<=n;i++){
			long long x;
			cin>>x;
			mp[x]++;
			ma=max(ma,mp[x]);
		}
		cout<<ma<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i) A=0;
	}
	long long aa=a[2]-a[1];
	for(int i=3;i<=n;i++)
		if(a[i]-a[i-1]!=aa){
			B=0;
			break;
		}
	if(A==1){
		long long s=0;
		for(int i=1;i<=n;i++){
			s+=i;
			if(s>m){
				cout<<i<<endl;
				return 0;
			}
		} 
		cout<<n<<endl;
		return 0;
	}
	if(B==1){
		long long s=0;
		for(int i=1;i<=n;i++){
			s+=aa*i;
			if(s>m){
				cout<<i<<endl;
				return 0;
			}
		}
		cout<<n<<endl;
		return 0;
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++)
		for(int j=1;j<i;j++) b[i][j]=a[i]-a[j]; 
	for(int i=2;i<n;i++){
		long long s=0;
		for(int j=1;j<i;j++) s+=b[i][j];
		if(s<=m) ma=max(ma,i); 
		s=0;
		for(int j=i+1;j<=n;j++){
			s+=b[j][i];
			if(s>m){
				ma=max(ma,j-i);
				break;
			}
		}
		if(s<=m) ma=max(ma,n-i+1); 
	}
	cout<<ma<<endl;
	return 0;
}

