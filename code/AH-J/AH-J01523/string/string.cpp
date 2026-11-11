#include<bits/stdc++.h>
using namespace std;
long long n,sum=0,s,a[200005],cnt[200];
bool f=1,f2=1;
char b[200005];
string str;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		scanf("%d %c",&a[i],&b[i]);
		if(b[i]!=b[i-1]&&i!=1)f=0;
		if(a[i]!=a[i-1]&&i!=1)f2=0;
		sum+=a[i]; 
	}
	if(f==1){
		cout<<0;
		return 0;
	}
	else if(f2==1){
		long long minn=999999999;
		for(int i=1;i<=n;i++){
			cnt[b[i]-'0']++;
		}
		for(int i=0;i<200;i++){
			if(cnt[i]!=0)minn=min(minn,n-cnt[i]);
		}
		cout<<minn*a[1];
		return 0;
	}
	else if(sum<=1e8){
		for(int i=1;i<=n;i++){
			for(long long j=1;j<=a[i];j++)str+=b[i];
		}
		long long l=0,r=sum-1;
		while(l<=r){
			if(str[l]==str[r]);
			else s++;
			l++,r--;
		}
		cout<<s;
		return 0;
	}
	else {	
		long long l=1,r=n,ls=0,rs=sum;
		while(l<=r&&ls<=rs){
			if(b[l]!=b[r]){
				if(a[l]<=a[r])s+=a[l],ls+=a[l],rs-=a[l],a[r]-=a[l],l++;
				if(a[l]>a[r])s+=a[r],rs-=a[r],ls+=a[r],a[l]-=a[r],r--;
			}
			else{
				if(a[l]<=a[r])ls+=a[l],rs-=a[l],a[r]-=a[l],l++;
				if(a[l]>a[r])rs-=a[r],ls+=a[r],a[l]-=a[r],r--;
			}
		}	
		cout<<s;
	}
	return 0;
}
