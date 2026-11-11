#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
long long a[500020]={0};
long long b[500021]={0};
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,ans=1,tempm;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i-1];
	}
	long long anscopy=ans,times=0;
	bool sign=false;
	for(long long i=0;i<n;i++){
		tempm=m;
		if(times>=10){
			if((ans>>8)+i<n-10){
				ans>>8;
			}
			sign=true;
			times=0;
			//cout<<'a'<<endl;
		}
		for(long long j=i+ans+1;j<=n;j++){
			if((j-i)*a[j-1]-(b[j]-b[i])<=tempm){
				if(sign==true){
					times=10;
					anscopy=ans;
				}
				ans=j-i;
				anscopy=ans;
				times++;
			}else{
				if(sign==true){
					times=0;
					ans=anscopy;
				}
				times--;
				break;
			}
		}
	}
	cout<<ans;
	fclose(stdin);fclose(stdout);
	return 0;
}
