#include<bits/stdc++.h>
using namespace std;
long long n,a[500005],last,m,lastn,p[5000005]; 
long long sum;
long long aa(long long s1,long long s2){
	long long s3=0;
	for(int i=1;i<=s2;i++){
		s3+=s1;
	}
	return s3;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	long long sl=1,sr=-1;
//	for(int i=1;i<=n;i++){
//		if(a[i]==a[i-1])sl++;
//		if(a[i]!=a[i-1])sr+=sl,cout<<a[i-1]<<":"<<sl<<" "<<sr<<endl,sl=1,p[++p[0]]=sr;
//	}
	last=a[1],lastn=a[1];
	for(long long i=1;i<=n;i++){
		long long h=aa((a[i]-last),(i-1));
		//cout<<sum<<" "<<a[i]<<" "<<last<<" "<<i<<endl;
		if(last!=a[i])lastn=last;
		if(sum+h>m){
			long long l1=1;
			for(long long j=i+1;j<=n;j++){
				if(a[j-1]!=a[j]){
					//cout<<l1+(m-sum)/(a[i]-lastn)<<" "<<l1<<" "<<(m-sum)<<" "<<a[i]<<" "<<lastn<<endl;
					cout<<max(i-1,l1+(m-sum)/(a[i]-lastn));
					return 0;
				}
				l1++;
			}
		}if(m==sum+h){
			cout<<i;
			return 0;
		}
		last=a[i];
		sum+=h;
	}
	cout<<1;
	return 0;
} 
