//GZ-J00080  贵阳市云岩区中天中学  熊昱皓 
#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,ans=0;
	cin>>n;
	vector<long long>a(n);
	vector<char>c(n);
	for(long long i=0;i<n;i++){
		cin>>a[i]>>c[i];
	}
	for(long long i=0,j=n-1;i<j;){
		while(a[i]>=a[j]&&i<j){
			a[i]-=a[j];
			if(c[i]!=c[j])ans+=a[j];
			j--;
		}
		while(a[j]>=a[i]&&i<j){
			a[j]-=a[i];
			if(c[i]!=c[j])ans+=a[i];
			i++;
		}
	}
	cout<<ans;
	return 0;
}
