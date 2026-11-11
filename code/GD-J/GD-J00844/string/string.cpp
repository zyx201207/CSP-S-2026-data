#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	unsigned long long s=0,sum=0;
	unsigned long long l[n];
	char c[n];
	unsigned char a[200005];
	for(int i=0;i<n;i++){
		cin>>l[i]>>c[i];
		s+=l[i];
	}
	if(s<200000){
		long long ss=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<l[i];j++){
				a[ss+j]=c[i];
			}
			ss+=l[i];
		}
		for(unsigned long long i=0;i<(s+1)/2;i++){
			if(a[i]!=a[s-i-1]){
				sum++;
			}
		}
		cout<<sum;
		return 0;
	}
	unsigned long long cnt=0,ss=0,sss=0;
	for(int i=0;i<(n+1)/2;i++){
		if(ss>=(s+1)/2||sss>=(s+1)/2){
			break;
		}
		if(cnt!=0){
			if(l[i-1]>l[n-i]){
				l[i]-=cnt;
			}
			else{
				l[n-i-1]-=cnt;
			}
			cnt=0;
		}
		if(c[i]==c[n-i-1]){
		}
		else{
			sum+=max(l[i],l[n-i-1]);
		}
		ss+=l[i];
		sss+=l[n-i-1];
		cnt=max(l[i],l[n-i-1])-min(l[i],l[n-i-1]);
	}
	cout<<sum;
	return 0;
}

