#include<bits/stdc++.h>
using namespace std;
int n;
long long a[500003];
long long m,mmax=-1e9,cnt=1,sum;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	if(n%2==1){
		long long temp2=a[n/2+1];
		for(int i=n/2;i>=1;i--){
			cnt++;
			sum+=temp2-a[i];
			if(sum>m){
				sum-=temp2-a[i];
				cnt--;
				break;
			}
		}
		for(int i=n/2+2;i<=n;i++){
			if(a[i]==temp2) cnt++;
			else break;
		}
		cout<<cnt<<'\n';
		return 0;
	}
	if(n%2==0){
		long long temp1=a[n/2],temp2=a[n/2+1];
		for(int i=n/2;i>=1;i--){
			cnt++;
			sum+=temp1-a[i];
			if(sum>m){
				sum-=temp1-a[i];
				cnt--;
				break;
			}
		}
		for(int i=n/2+1;i<=n;i++){
			if(a[i]==temp1) cnt++;
			else break;
		}
		if(cnt>mmax) mmax=cnt;
		cnt=1,sum=0;
		for(int i=n/2;i>=1;i--){
			cnt++;
			sum+=temp2-a[i];
			if(sum>m){
				sum-=temp2-a[i];
				cnt--;
				break;
			}
		}
		for(int i=n/2+2;i<=n;i++){
			if(a[i]==temp2) cnt++;
			else break;
		}
		if(cnt>mmax) mmax=cnt;
		cout<<mmax<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
